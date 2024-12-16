/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floodfill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:59:09 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/12 15:17:21 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	flood_fill(int x, int y, t_data *data, char **visited, char unwanted)
{
	int	up;
	int	down;
	int	left;
	int	right;

	if (x < 0 || y < 0 || x >= data->rows || y >= data->cols)
		return (0);
	if (data->map[x][y] == unwanted)
		return (0);
	if (data->map[x][y] == '1' || visited[x][y] == '1')
		return (1);
	visited[x][y] = '1';
	up = flood_fill(x, y - 1, data, visited, unwanted);
	down = flood_fill(x, y + 1, data, visited, unwanted);
	left = flood_fill(x - 1, y, data, visited, unwanted);
	right = flood_fill(x + 1, y, data, visited, unwanted);
	return (up && down && left && right);
}

char	**create_visited_matrix(t_data *data)
{
	char	**visited;
	int		i;
	int		j;

	visited = (char **)malloc((data->rows + 1) * sizeof(char *));
	i = 0;
	while (i < data->rows)
	{
		visited[i] = (char *)malloc((data->cols + 1) * sizeof(char));
		j = 0;
		while (j < data->cols)
		{
			visited[i][j] = 0;
			j++;
		}
		visited[i][j] = '\0';
		i++;
	}
	visited[i] = NULL;
	return (visited);
}

void	flood_fill_wall_check(t_data *data)
{
	char	**visited;
	int		result;
	int		point_x;
	int		point_y;
	int		i;
	int		j;

	visited = create_visited_matrix(data);
	point_x = -1;
	point_y = -1;
	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || \
				data->map[i][j] == 'W' || data->map[i][j] == 'E')
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
	result = flood_fill(point_x, point_y, data, visited, '*');
	free_array(visited);
	if (result == 0)
	{
		printf("Error. The walls on the map don't enclose "); 
		printf("the inside space around the player.\n\n");
		free_everything(data);
		exit(EXIT_FAILURE);
	}
}

void	flood_fill_space_check(t_data *data)
{
	char	**visited;
	int		result;
	int		point_x;
	int		point_y;
	int		i;
	int		j;

	visited = create_visited_matrix(data);
	point_x = -1;
	point_y = -1;
	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || \
				data->map[i][j] == 'W' || data->map[i][j] == 'E')
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
	result = flood_fill(point_x, point_y, data, visited, ' ');
	free_array(visited);
	if (result == 0)
	{
		printf("Error. There are unexpected spaces on the map.\n\n");
		free_everything(data);
		exit(EXIT_FAILURE);
	}
}
