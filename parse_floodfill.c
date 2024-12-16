/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floodfill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:59:09 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/16 15:26:40 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	flood_fill_space(int x, int y, t_data *data, char **visited)
{
	int		up;
	int		down;
	int		left;
	int		right;
	char	unwanted;

	unwanted = ' ';
	if (x < 0 || y < 0 || x >= data->rows || y >= data->cols)
		return (0);
	if (data->map[x][y] == unwanted)
		return (0);
	if (data->map[x][y] == '1' || visited[x][y] == '1')
		return (1);
	visited[x][y] = '1';
	up = flood_fill_space(x, y - 1, data, visited);
	down = flood_fill_space(x, y + 1, data, visited);
	left = flood_fill_space(x - 1, y, data, visited);
	right = flood_fill_space(x + 1, y, data, visited);
	return (up && down && left && right);
}

int	flood_fill_wall(int x, int y, t_data *data, char **visited)
{
	int		up;
	int		down;
	int		left;
	int		right;
	char	unwanted;

	unwanted = '*';
	if (x < 0 || y < 0 || x >= data->rows || y >= data->cols)
		return (0);
	if (data->map[x][y] == unwanted)
		return (0);
	if (data->map[x][y] == '1' || visited[x][y] == '1')
		return (1);
	visited[x][y] = '1';
	up = flood_fill_wall(x, y - 1, data, visited);
	down = flood_fill_wall(x, y + 1, data, visited);
	left = flood_fill_wall(x - 1, y, data, visited);
	right = flood_fill_wall(x + 1, y, data, visited);
	return (up && down && left && right);
}

void	flood_fill_wall_check(t_data *data)
{
	char	**visited;
	int		result;
	int		point_x;
	int		point_y;

	visited = create_visited_matrix(data);
	point_x = -1;
	point_y = -1;
	look_for_player(data, &point_x, &point_y);
	result = flood_fill_wall(point_x, point_y, data, visited);
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

	visited = create_visited_matrix(data);
	point_x = -1;
	point_y = -1;
	look_for_player(data, &point_x, &point_y);
	result = flood_fill_space(point_x, point_y, data, visited);
	free_array(visited);
	if (result == 0)
	{
		printf("Error. There are unexpected spaces on the map.\n\n");
		free_everything(data);
		exit(EXIT_FAILURE);
	}
}
