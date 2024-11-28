/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vertical_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:20:16 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/28 17:31:08 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	find_vertical_wall(t_data *data, double viewing_angle, int direction)
{
	t_point	border;
	t_point	cube;
	double dX;
	double dY;

	if (direction == RIGHT)
		border.x = floor(data->player->position->x/CUBE_SIZE) * (CUBE_SIZE) + CUBE_SIZE;
	else if (direction == LEFT)
		border.x = floor(data->player->position->x/CUBE_SIZE) * (CUBE_SIZE) - 1;
	if (viewing_angle == 0 || viewing_angle == 180)
		border.y = data->player->position->y;
	else
		border.y = data->player->position->y + (data->player->position->x - border.x) * tan(viewing_angle / (double)180 * M_PI);
	cube.x = floor(border.x / CUBE_SIZE);
	cube.y = floor(border.y / CUBE_SIZE);
	if (cube.x < 0 || cube.x >= data->cols || cube.y < 0 || cube.y >= data->rows)
		return (-1);
	while (data->map[(int)cube.y][(int)cube.x] != '1')
	{
		if (direction == RIGHT)
			dX = CUBE_SIZE;
		else if (direction == LEFT)
			dX = CUBE_SIZE * -1;
		if (viewing_angle == 0 || viewing_angle == 180)
			dY = 0;
		else
			dY = CUBE_SIZE * tan(viewing_angle / (double)180 * M_PI);
		border.x += dX; 
		border.y += dY;
		cube.x = floor(border.x / (double)CUBE_SIZE);
		cube.y = floor(border.y / (double)CUBE_SIZE);
		if (cube.x < 0 || cube.x >= data->cols || cube.y < 0 || cube.y >= data->rows)
		{
			// printf("vertical: exited in while loop\n");
			// printf("\n\nvertical - x: %d\ny: %d\n", (int)floor(cube.x), (int)floor(cube.y));
			// printf("border: x=%f, y=%f\n", border.x, border.y);
			// printf("value of viewing angle: %f.\n\n", viewing_angle);
			return (-1);
		}
	}
	// printf("\n\nvertical - x: %d\ny: %d\n", (int)floor(cube.x), (int)floor(cube.y));
	// printf("border: x=%f, y=%f\n", border.x, border.y);
	// printf("value of viewing angle: %f.\n\n", viewing_angle);
	return (calculate_distance(data, &border, viewing_angle));
}
