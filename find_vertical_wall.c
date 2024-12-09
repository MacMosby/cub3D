/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vertical_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:20:16 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/11 17:20:39 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_point	find_first_vertical_hit(t_data *data, int direction, double v_angle)
{
	t_point	point;

	if (direction == NE || direction == E || direction == SE)
		point.x = floor(data->player->position->x / CUBE_SIZE) * (CUBE_SIZE) + CUBE_SIZE;
	else if (direction == NW || direction == W || direction == SW)
		point.x = floor(data->player->position->x / CUBE_SIZE) * (CUBE_SIZE) - 0.001;
	if (direction == E || direction == W)
		point.y = data->player->position->y;
	else
		point.y = data->player->position->y + (data->player->position->x - point.x) * tan(v_angle / (double)180 * M_PI);
	return	(point);
}

t_point	get_grid_position(t_point point)
{
	t_point	cube;

	cube.x = floor(point.x / CUBE_SIZE);
	cube.y = floor(point.y / CUBE_SIZE);
	return (cube);
}

double	set_dX_vertical(int direction)
{
	if (direction == NE || direction == E || direction == SE)
		return (CUBE_SIZE);
	else //if (direction == NW || direction == W || direction == SW)
		return (CUBE_SIZE * -1);
}

double	set_dY_vertical(double v_angle)
{
	if (v_angle == 0 || v_angle == 180)
		return (0);
	else
		return (CUBE_SIZE * tan(v_angle / (double)180 * M_PI));
}

t_point	get_next_vertical_hit(t_point point, int direction, double v_angle)
{
	double	dX;
	double	dY;

	dX = set_dX_vertical(direction);
	point.x += dX;
	dY = set_dY_vertical(v_angle);
	if (direction == NE)
		point.y -= dY;
	else if (direction == NW)
		point.y += dY;
	else if (direction == SW)
		point.y += dY;
	else if (direction == SE)
		point.y -= dY;
	//point.y += dY;
	return (point);
}

t_point	find_vertical_wall(t_data *data, double v_angle, int direction, double *dist)
{
	t_point	point;
	t_point	cube;

	point = find_first_vertical_hit(data, direction, v_angle);
	cube = get_grid_position(point);
	if (cube.x < 0 || cube.x >= data->cols || cube.y < 0 || cube.y >= data->rows)
	{
		*dist = -1;
		return (point);
	}
	while (data->map[(int)cube.y][(int)cube.x] != '1')
	{
		point = get_next_vertical_hit(point, direction, v_angle);
		cube = get_grid_position(point);
		if (cube.x < 0 || cube.x >= data->cols || cube.y < 0 || cube.y >= data->rows)
		{
			/* printf("vertical: exited in while loop\n");
			printf("\n\nvertical - x: %d\ny: %d\n", (int)floor(cube.x), (int)floor(cube.y));
			printf("point: x=%f, y=%f\n", point.x, point.y);
			printf("value of viewing angle: %f.\n\n", v_angle); */
			*dist = -1;
			return (point);
		}
	}
	// printf("\n\nvertical - x: %d\ny: %d\n", (int)floor(cube.x), (int)floor(cube.y));
	// printf("point: x=%f, y=%f\n", point.x, point.y);
	// printf("value of viewing angle: %f.\n\n", v_angle);
	// printf("Vertical wall point values: x = %f, y = %f\n", point.x, point.y);
	// printf("Vertical wall cube values: x = %f, y = %f\n", cube.x, cube.y);
	*dist = calculate_distance(data, &point, v_angle);
	return (point);
}
