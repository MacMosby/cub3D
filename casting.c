/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:14:00 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/09 11:45:02 by lde-taey         ###   ########.fr       */
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

void	cast_slice(t_data *data, double wall_distance, int col, int offset, int wall)
{
	int i = 0;
	int	slice_height;
	int	ceiling_floor_height;

	slice_height = CUBE_SIZE * (PLANE_DIST / wall_distance);
	//printf("slice height: %d\n", slice_height);
	ceiling_floor_height = (HEIGHT - slice_height) / 2;
	//printf("floor height: %d\n", ceiling_floor_height);
	// drawing the ceiling
	while (i < ceiling_floor_height)
	{
		my_pixel_put(col, i, &data->imag, SKY_BLUE);
		i++;
	}
	// drawing the wall
	// printf("offset: %d\n", offset);
	while (i < HEIGHT - ceiling_floor_height)
	{
		if (wall == E)
			my_pixel_put(col, i, &data->imag, *(unsigned int *)(data->ea_img.pixels_ptr + ((i - ceiling_floor_height) * CUBE_SIZE / slice_height * data->ea_img.line_len) + (offset * data->ea_img.bpp / 8)));
		else if (wall == N)
			my_pixel_put(col, i, &data->imag, *(unsigned int *)(data->no_img.pixels_ptr + ((i - ceiling_floor_height) * CUBE_SIZE / slice_height * data->no_img.line_len) + (offset * data->no_img.bpp / 8)));
		else if (wall == W)
			my_pixel_put(col, i, &data->imag, *(unsigned int *)(data->we_img.pixels_ptr + ((i - ceiling_floor_height) * CUBE_SIZE / slice_height * data->we_img.line_len) + (offset * data->we_img.bpp / 8)));
		else if (wall == S)
			my_pixel_put(col, i, &data->imag, *(unsigned int *)(data->so_img.pixels_ptr + ((i - ceiling_floor_height) * CUBE_SIZE / slice_height * data->so_img.line_len) + (offset * data->so_img.bpp / 8)));
		i++;
	}
	// drawing the floor
	while (i < HEIGHT)
	{
		my_pixel_put(col, i, &data->imag, CLAY_RED);
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
