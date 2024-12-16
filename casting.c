/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:14:00 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/12 11:10:10 by lde-taey         ###   ########.fr       */
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

void	draw_ceiling(t_data *data, int ceiling_height, int *i, int col)
{
	while (*i < ceiling_height)
	{
		my_pixel_put(col, *i, &data->imag, METAL);
		(*i)++;
	}
}

void	draw_floor(t_data *data, int *i, int col)
{
	while (*i < HEIGHT)
	{
		my_pixel_put(col, *i, &data->imag, METALLIC_BLACK);
		(*i)++;
	}
}

int	set_color(t_data *data, int wall_row, int slice_height, int offset)
{
	int	color;

	color = 0;
	if (data->wall == E)
		color = *(unsigned int *)(data->ea_img.pixels_ptr + ((wall_row)
					* CUBE_SIZE / slice_height * data->ea_img.line_len)
				+ (offset * data->ea_img.bpp / 8));
	else if (data->wall == N)
		color = *(unsigned int *)(data->no_img.pixels_ptr + ((wall_row)
					* CUBE_SIZE / slice_height * data->no_img.line_len)
				+ (offset * data->no_img.bpp / 8));
	else if (data->wall == W)
		color = *(unsigned int *)(data->we_img.pixels_ptr + ((wall_row)
					* CUBE_SIZE / slice_height * data->we_img.line_len)
				+ (offset * data->we_img.bpp / 8));
	else if (data->wall == S)
		color = *(unsigned int *)(data->so_img.pixels_ptr + ((wall_row)
					* CUBE_SIZE / slice_height * data->so_img.line_len)
				+ (offset * data->so_img.bpp / 8));
	return (color);
}

void	cast_slice(t_data *data, double wall_distance, int col, int offset)
{
	int	i;
	int	slice_height;
	int	floor_height;
	int	color;

	slice_height = CUBE_SIZE * (PLANE_DIST / wall_distance);
	floor_height = (HEIGHT - slice_height) / 2;
	i = 0;
	draw_ceiling(data, floor_height, &i, col);
	while (i < HEIGHT - floor_height)
	{
		color = set_color(data, i - floor_height, slice_height, offset);
		my_pixel_put(col, i, &data->imag, color);
		i++;
	}
	draw_floor(data, &i, col);
}
