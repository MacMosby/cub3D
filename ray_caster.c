/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:14:00 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/05 14:14:02 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* calculates and returns the distance to the next wall based on the
x-coordinate of the player, the x-coordinate of the next wall and the player's
viewing angle */
double	calculate_distance(t_point *player, t_point *wall)
{
	return (fabs(data->player->position->x - wall->x) / cos(ALPHA));
}

void	find_vertical_wall(t_data *data)
{
	t_point	border;
	t_point	cube;
	// getting x coordinate of Point B
	// if ray is facing right
	border.x = rounded_down(data->player->position->x/CUBE_SIZE) * (CUBE_SIZE) + 64;
	// if ray is facing left
	border.x = rounded_down(data->player->position->x/CUBE_SIZE) * (CUBE_SIZE) + CUBE_SIZE;
	// getting x coordinate of the grid it belongs to
	cube.x = border.x / CUBE_SIZE;
	// getting y coordinate of Point B
	border.y = data->player->position->y + ((data->player->position->x - border.x)/tan(ALPHA));
	// getting y coordinate of the grid it belongs to
	cube.x = border.x / CUBE_SIZE;
	while (map[cube.y][cube.x] != 1)
	{
		// go for next point
		// finding dX which is always the size of a cube and dY
		///path_ if ray is facing right it is positive
		dX = CUBE_SIZE;
		// if ray is facing left it is negative
		dX = CUBE_SIZE * -1;
		// finding dY
		dY = CUBE_SIZE/tan(ALPHA);
		border.x += dX;
		cube.x = border.x / CUBE_SIZE;
		border.y += dY;
		cube.y = border.y / CUBE_SIZE;
	}
	return (calculate_distance(data->player, border));
}

void	find_horizontal_wall(t_data *data)
{
	t_point	border;
	t_point	cube;
	int		dX;
	int		dY;

	// getting y coordinate of Point A
	// if ray is facing up
	border.y = rounded_down(data->player->position->y/typedef struct s_point
{
	double	x;
	double	y;
}	t_point;CUBE_SIZE) * (CUBE_SIZE) - 1;
	// if ray is facing down
	border.y = rounded_down(data->player->position->y/CUBE_SIZE) (CUBE_SIZE) + CUBE_SIZE;
	// getting y coordinate of the grid it belongs to
	cube.y = border.y / CUBE_SIZE;
	// getting x coordinate of Point A
	border.x = data->player->position->x + ((data->player->position->y - border.y)/tan(ALPHA));
	// getting x coordinate of the grid it belongs to
	cube.x = border.x / CUBE_SIZE;
	// checking if grid of A if a wall
	while (map[cube.y][cube.x] != 1)
	{
		// go for next point
		// finding dY which is always the size of a cube and dX
		// if ray is facing up it is negative
		dY = CUBE_SIZE * -1;
		// if ray is facing down it is positive
		dY = CUBE_SIZE;
		// finding dX
		dX = CUBE_SIZE/tan(data->player->angle);
		border.x += dX;
		cube.x = border.x / CUBE_SIZE;
		border.y += dY;
		cube.y = border.y / CUBE_SIZE;
	}
	return (calculate_distance(data->player, border));
}

double	get_correct_distance(double hori_dist, double vert_dist)
{
	if (hori_dist < vert_dist)
		return (hori_dist * cos(BETA));
	else
		return (vert_dist * cos(BETA));
}

void	cast_slice(t_data *data, double wall_distance)
{
	int	slice_height;

	slice_height = CUBE_SIZE * (PLANE_DIST / wall_distance);
	// middle of slice should be in the the middle of the screen
		// (window height/2) - (slice height/2)
	// finding the offset of the bitmap to find the
	// right slice to shoot onto the wall
		// if slice on vertical grid boundary
			// offset = P.y % CUBE_SIZE
		// if slice on horizontal grid boundary
			// offset = P.x % CUBE_SIZE
}

void	cast_ray(void)
{
	double	vert_dist;
	double	hori_dist;
	double	real_dist;

	hori_dist = find_horizontal_wall();
	vert_dist = find_vertical_wall();
	real_dist = get_correct_distance(hori_dist, vert_dist);
	cast_slice(real_dist);
}

void	ray_caster(void)
{
	int i = 0;

	// How to point to the first column??
	while (i < SCREEN_WIDTH)
	{
		cast_ray();
		i++;
	}
}
