/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horizontal_wall.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:19:36 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/21 14:28:45 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	find_horizontal_wall(t_data *data, double viewing_angle, int direction)
{
	t_point	border;
	t_point	cube;
	double		dX;
	double		dY;

	if (direction == UP)
		border.y = floor(data->player->position->y/CUBE_SIZE) * (CUBE_SIZE) - 1;
	else if (direction == DOWN)
		border.y = floor(data->player->position->y/CUBE_SIZE) * (CUBE_SIZE) + CUBE_SIZE;
	if (viewing_angle == 90 || viewing_angle == 270)
		border.x = data->player->position->x;
	else
		border.x = data->player->position->x + (data->player->position->y - border.y)/tan(viewing_angle / (double)180 * M_PI);
	cube.y = floor(border.y / (double)CUBE_SIZE);
	cube.x = floor(border.x / (double)CUBE_SIZE);
	if (cube.x < 0 || cube.x >= data->cols || cube.y < 0 || cube.y >= data->rows)
		return (-1);
	while (data->map[(int)cube.y][(int)cube.x] != '1')
	{
		// go for next point
		// finding dY which is always the size of a cube and dX
		// if ray is facing up it is negative
		if (direction == UP)
			dY = (double)(CUBE_SIZE * -1);
		// if ray is facing down it is positive
		else if (direction == DOWN)
			dY = (double)CUBE_SIZE;
		// finding dX
		if (viewing_angle == 90 || viewing_angle == 270)
			dX = 0;
		else
			dX = (double)CUBE_SIZE/tan(viewing_angle / (double)180 * M_PI);
		border.x += dX;
		border.y += dY;
		cube.x = floor(border.x / (double)CUBE_SIZE);
		cube.y = floor(border.y / (double)CUBE_SIZE);
		if (cube.x < 0 || cube.x >= data->cols || cube.y < 0 || cube.y >= data->rows)
			return (-1);
	}
	printf("horizontal - x: %d\ny: %d\n", (int)floor(cube.x), (int)floor(cube.y));
	return (calculate_distance(data->player->position, &border, viewing_angle));
}