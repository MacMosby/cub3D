/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horizontal_wall.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:19:36 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/26 13:57:48 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	find_horizontal_wall(t_data *data, double viewing_angle, int direction)
{
	t_point	border; // should this be malloced if information is passed?
	t_point next;
	t_point	cube;
	t_point next_cube;
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
	// {
	// 	printf("\nreturned before while loop in horizontal part.\n");
	// 	printf("value of viewing angle: %f.\n", viewing_angle);
	// 	printf("direction: %i\n", direction);
	// 	printf("border found: x=%f, y=%f\n", border.x, border.y);
	// 	printf("cube: x=%d, y=%d\n", (int)cube.x, (int)cube.y);
	// 	printf("value of player position x: %f.\n", data->player->position->x);
	// 	printf("value of player position y: %f\n", data->player->position->y);
	// 	return (-1);
	// }
	while (1)
	{
		// go for next point
		// finding dY which is always the size of a cube and dX
		// if ray is facing up it is negative
		cube.y = floor(border.y / (double)CUBE_SIZE);
		cube.x = floor(border.x / (double)CUBE_SIZE);
		if (cube.x < 0 || cube.x >= data->cols || cube.y < 0 || cube.y >= data->rows)
			return (-1);
		if (data->map[(int)cube.y][(int)cube.x] == '1')
			break;
		if (direction == UP)
			dY = (double)(CUBE_SIZE * -1);
		// if ray is facing down it is positive
		else // if (direction == DOWN)
			dY = (double)CUBE_SIZE;
		// finding dX
		if (viewing_angle == 90 || viewing_angle == 270)
			dX = 0;
		else
			dX = (double)CUBE_SIZE/tan(viewing_angle / (double)180 * M_PI);
		
		next.x = border.x + dX;
		next.y = border.y + dY;
		next_cube.x = floor(next.x / (double)CUBE_SIZE);
		next_cube.y = floor(next.y / (double)CUBE_SIZE);
		if (next_cube.x < 0 || next_cube.x >= data->cols || next_cube.y < 0 || next_cube.y >= data->rows)
		{
			// printf("\nreturned in while loop in horizontal part.\n");
			// printf("value of viewing angle: %f.\n", viewing_angle);
			// printf("direction: %i\n", direction);
			// printf("border found: x=%f, y=%f\n", border.x, border.y);
			// printf("difference: dX=%f, dY=%f\n", dX, dY);
			// printf("cube: x=%d, y=%d\n", (int)cube.x, (int)cube.y);
			// printf("value of player position x: %f.\n", data->player->position->x);
			// printf("value of player position y: %f\n", data->player->position->y);
			return (-1);
		}
		border.x = next.x;
		border.y = next.y;
	}
	// printf("horizontal - x: %d\ny: %d\n", (int)floor(cube.x), (int)floor(cube.y));
	return (calculate_distance(data->player->position, &border, viewing_angle));
}
