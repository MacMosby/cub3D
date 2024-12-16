/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horizontal_wall.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:19:36 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/11 17:20:48 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_point	find_first_horizontal_hit(t_data *data, int direction, double v_angle)
{
	t_point	point;

	if (direction == NE || direction == N || direction == NW)
		point.y = floor(data->player->position->y / CUBE_SIZE)
			* (CUBE_SIZE) - 0.001;
	else if (direction == SW || direction == S || direction == SE)
		point.y = floor(data->player->position->y / CUBE_SIZE)
			* (CUBE_SIZE) + CUBE_SIZE;
	if (direction == N || direction == S)
		point.x = data->player->position->x;
	else
		point.x = data->player->position->x + (data->player->position->y
				- point.y) / tan(v_angle / (double)180 * M_PI);
	return (point);
}

/* setting dy depending if the ray is facing up or down */
double	set_dy_horizontal(int direction)
{
	if (direction == NE || direction == N || direction == NW)
		return ((double)(CUBE_SIZE * -1));
	else
		return ((double)CUBE_SIZE);
}

double	set_dx_horizontal(double v_angle)
{
	if (v_angle == 90 || v_angle == 270)
		return (0);
	else
		return ((double)CUBE_SIZE / tan(v_angle / (double)180 * M_PI));
}

t_point	get_next_horizontal_hit(t_point point, int direction, double v_angle)
{
	double	dx;
	double	dy;

	dy = set_dy_horizontal(direction);
	point.y += dy;
	dx = set_dx_horizontal(v_angle);
	if (direction == NE)
		point.x += dx;
	else if (direction == NW)
		point.x += dx;
	else if (direction == SW)
		point.x -= dx;
	else if (direction == SE)
		point.x -= dx;
	return (point);
}

t_point	find_horizontal_wall(t_data *data, double angle, int dir, double *dist)
{
	t_point	point;
	t_point	cube;

	point = find_first_horizontal_hit(data, dir, angle);
	cube = get_grid_position(point);
	if (cube.x < 0 || cube.x >= data->cols
		|| cube.y < 0 || cube.y >= data->rows)
	{
		*dist = -1;
		return (point);
	}
	while (data->map[(int)cube.y][(int)cube.x] != '1')
	{
		point = get_next_horizontal_hit(point, dir, angle);
		cube = get_grid_position(point);
		if (cube.x < 0 || cube.x >= data->cols
			|| cube.y < 0 || cube.y >= data->rows)
		{
			*dist = -1;
			return (point);
		}
	}
	*dist = calculate_distance(data, &point);
	return (point);
}
