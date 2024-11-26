/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:14:00 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/26 17:30:30 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	get_correct_distance(double hori_dist, double vert_dist, double angle)
{
	if (hori_dist < 0)
		return (vert_dist * cos(angle / (double)180 * M_PI));
	if (vert_dist < 0)
		return (hori_dist * cos(angle / (double)180 * M_PI));
	if (hori_dist < vert_dist)
		return (hori_dist * cos(angle / (double)180 * M_PI));
	else
		return (vert_dist * cos(angle / (double)180 * M_PI));
}

void	cast_slice(t_data *data, double wall_distance, int col)
{
	int i = 0;
	int	slice_height;
	int	ceiling_floor_height;

	slice_height = CUBE_SIZE * (PLANE_DIST / wall_distance);
	//printf("slice height: %d\n", slice_height);
	ceiling_floor_height = (HEIGTH - slice_height) / 2;
	//printf("floor height: %d\n", ceiling_floor_height);
	// drawing the ceiling
	while (i < ceiling_floor_height)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, col, i, 0xFF0000);
		i++;
	}
	// drawing the wall
	while (i < HEIGTH - ceiling_floor_height)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, col, i, 0x00FF00);
		i++;
	}
	// drawing the floor
	while (i < HEIGTH)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, col, i, 0x0000FF);
		i++;
	}
	// middle of slice should be in the the middle of the screen
		// (window height/2) - (slice height/2)
	// finding the offset of the bitmap to find the
	// right slice to shoot onto the wall
		// if slice on vertical grid boundary
			// offset = P.y % CUBE_SIZE
		// if slice on horizontal grid boundary
			// offset = P.x % CUBE_SIZE
}




