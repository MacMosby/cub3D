/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horizontal_wall.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:19:36 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/28 17:31:01 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_point	find_first_horizontal_hit(t_data *data, int direction, double v_angle)
{
	t_point	point;

	if (direction == NE || direction == N || direction == NW)
		point.y = floor(data->player->position->y/CUBE_SIZE) * (CUBE_SIZE) - 1;
	else if (direction == SW || direction == S || direction == SE)
		point.y = floor(data->player->position->y/CUBE_SIZE) * (CUBE_SIZE) + CUBE_SIZE;
	if (direction == N || direction == S)
		point.x = data->player->position->x;
	else
		point.x = data->player->position->x + (data->player->position->y - point.y)/tan(v_angle / (double)180 * M_PI);
	return (point);
}

double	set_dY_horizontal(int direction)
{
	if (direction == NE || direction == N || direction == NW)
		return((double)(CUBE_SIZE * -1));
	else //if (direction == SW || direction == S || direction == SE)
		return ((double)CUBE_SIZE);
}

double	set_dX_horizontal(double v_angle)
{
	if (v_angle == 90 || v_angle == 270)
		return (0);
	else
		return ((double)CUBE_SIZE/tan(v_angle / (double)180 * M_PI));
}

t_point	get_next_horizontal_hit(t_point point, int direction, double v_angle)
{
	double	dX;
	double	dY;

	dY = set_dY_horizontal(direction);
	point.y += dY;
	dX = set_dX_horizontal(v_angle);
	//point.x += dX;
	if (direction == NE)
		point.x += dX;
	else if (direction == NW)
		point.x += dX;
	else if (direction == SW)
		point.x -= dX;
	else if (direction == SE)
		point.x -= dX;
	return (point);
}

double	find_horizontal_wall(t_data *data, double v_angle, int direction)
{
	t_point	point;
	t_point	cube;

	point = find_first_horizontal_hit(data, direction, v_angle);
	cube = get_grid_position(point);
	if (cube.x < 0 || cube.x >= data->cols || cube.y < 0 || cube.y >= data->rows)
		return (-1);
	while (data->map[(int)cube.y][(int)cube.x] != '1')
	{
		point = get_next_horizontal_hit(point, direction, v_angle);
		cube = get_grid_position(point);
		if (cube.x < 0 || cube.x >= data->cols || cube.y < 0 || cube.y >= data->rows)
		{
			/* printf("horizontal: exited in while loop");
			printf("\n\nhorizontal - x: %d\ny: %d\n", (int)floor(cube.x), (int)floor(cube.y));
			printf("point: x=%f, y=%f\n", point.x, point.y);
			printf("dX: %f\n", dX);
			printf("dY: %f\n", dY);
			printf("value of viewing angle: %f.\n\n", v_angle); */
			return (-1);
		}
	}
	// printf("\n\nhorizontal - x: %d\ny: %d\n", (int)floor(cube.x), (int)floor(cube.y));
	// printf("point: x=%f, y=%f\n", point.x, point.y);
	// printf("value of viewing angle: %f.\n\n", v_angle);
	return (calculate_distance(data, &point, v_angle));
}
