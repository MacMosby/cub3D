/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vertical_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:20:16 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/26 13:51:45 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	find_vertical_wall(t_data *data, double viewing_angle, int direction)
{
	t_point	border;
	t_point	cube;
	t_point next;
	t_point next_cube;
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
	// {
	// 	printf("\nreturned before while loop in vertical part.\n");
	// 	printf("border: x=%f, y=%f\n", border.x, border.y);
	// 	printf("cube: x=%d, y=%d\n", (int)cube.x, (int)cube.y);
	// 	printf("value of viewing angle: %f.\n", viewing_angle);
	// 	printf("value of player position x: %f.\n", data->player->position->x);
	// 	printf("value of player position y: %f\n", data->player->position->y);
	// 	return (-1);
	// }
	while (1)
	{
		cube.x = floor(border.x / CUBE_SIZE);
		cube.y = floor(border.y / CUBE_SIZE);
		if (cube.x < 0 || cube.x >= data->cols || cube.y < 0 || cube.y >= data->rows)
			return (-1);
		if (data->map[(int)cube.y][(int)cube.x] == '1')
			break;
		if (direction == RIGHT)
			dX = CUBE_SIZE;
		else if (direction == LEFT)
			dX = CUBE_SIZE * -1;
		if (viewing_angle == 0 || viewing_angle == 180)
			dY = 0;
		else
			dY = CUBE_SIZE * tan(viewing_angle / (double)180 * M_PI);
		next.x = border.x + dX; // I think this should not be changed if the ray goes out of bounds bc it will return -1
		next.y = border.y + dY;
		next_cube.x = floor(next.x / (double)CUBE_SIZE);
		next_cube.y = floor(next.y / (double)CUBE_SIZE);
		if (next_cube.x < 0 || next_cube.x >= data->cols || next_cube.y < 0 || next_cube.y >= data->rows)
		{
			// printf("\nreturned in while loop in vertical part.\n");
			// printf("border: x=%f, y=%f\n", border.x, border.y);
			// printf("cube: x=%d, y=%d\n", (int)cube.x, (int)cube.y);
			// printf("value of viewing angle: %f.\n", viewing_angle);
			// printf("value of player position x: %f.\n", data->player->position->x);
			// printf("value of player position y: %f\n", data->player->position->y);
			return (-1);
		}
		border.x = next.x;
		border.y = next.y;
	}
	return (calculate_distance(data->player->position, &border, viewing_angle));
}
