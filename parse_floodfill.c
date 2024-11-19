/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floodfill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:59:09 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/19 11:33:05 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	flood_fill(int x, int y, t_data *data, char **visited)
{
	int up;
	int down;
	int left;
	int	right;
	
	if (x < 0 || y < 0 || x >= data->rows || y >= data->cols)
		return (1);
	if (data->map[x][y] == '*')
		return (1);
	if (data->map[x][y] == '1' || visited[x][y] == '1')
		return (0);
	visited[x][y] = '1';
	up = flood_fill(x, y - 1, data, visited);
	down = flood_fill(x, y + 1, data, visited);
	left = flood_fill(x - 1, y, data, visited);
	right = flood_fill(x + 1, y, data, visited);

	return (up && down && left && right);
}

void flood_fill_check(t_data *data)
{
	char **visited;
	int	i;
	int	j;
	int point_x;
	int point_y;
	int result;
	
	// create visited matrix
	visited = (char **)malloc((data->rows + 1) * sizeof(char *));
	i = 0;
	while(i < data->rows)
	{
		visited[i] = (char *)malloc((data->cols + 1) * sizeof(char));
		j = 0;
		while(j < data->cols)
		{
			visited[i][j] = 0;
			j++;
		}
		visited[i][j] = '\0';
		i++;
	}
	visited[i] = NULL;

	// look for starting point
	point_x = -1;
	point_y = -1;
	i = 0;
	while(i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->map[i][j] == '0' || data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				point_x = i;
				point_y = j;
				break ;
			}
			j++;
		}
		if (point_x != -1)
			break ;
		i++;
	}

	// if no empty space is found -- assume surrounded
	if (point_x == -1)
		return ;

	// perform flood_fill
	result = flood_fill(point_x, point_y, data, visited);

	// free visited matrix
	free_array(visited);

	// deal with result
	if (result == 1)
	{
		printf("Error. The walls on the map don't enclose the inside space.\n\n");
		free_everything(data);
		exit(EXIT_FAILURE);
	}
	else
		printf("--> Map is alright\n\n");
}
