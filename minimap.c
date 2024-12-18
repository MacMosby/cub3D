/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:28:59 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/18 14:37:20 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_and_put_pixel(t_data *data, int color, int i, int j)
{
	float	pixx;
	float	pixy;
	float	scaled_x;
	float	scaled_y;

	pixy = 0;
	while (pixy < MAP_CELL)
	{
		pixx = 0;
		while (pixx < MAP_CELL) 
		{
			scaled_x = pixx + MAP_CELL * j - data->mm_xstart;
			scaled_y = pixy + MAP_CELL * i - data->mm_ystart;
			if (scaled_x >= 0 && scaled_x < MM_WIDTH && \
				scaled_y >= 0 && scaled_y < MM_HEIGHT)
				my_pixel_put((scaled_x + MM_OFFSET), \
					(scaled_y + MM_OFFSET), &data->imag, color);
			pixx++;
		}
		pixy++;
	}
}

void	draw_scaledminimap(t_data *data)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	j = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->map[i][j] == '1')
				color = METAL;
			else if (data->map[i][j] == '*')
				color = GREY;
			else
				color = SILVERY;
			calculate_and_put_pixel(data, color, i, j);
			j++;
		}
		i++;
	}
	draw_player(data);
}

void	draw_frame(t_data *data)
{
	if (MM_HEIGHT > data->rows * MAP_CELL && MM_WIDTH > data->cols * MAP_CELL)
		draw_small_frame(data);
	else if (MM_HEIGHT > data->rows * MAP_CELL || \
		MM_WIDTH > data->cols * MAP_CELL)
		draw_adjusted_frame(data);
	else
		draw_minimap_frame(data);
}

void	draw_minimap(t_data *data)
{
	float	width_bigmmap;
	float	height_bigmmap;

	data->mm_xstart = data->player->position->x * MAP_CELL / \
		CUBE_SIZE - MM_WIDTH / 2;
	data->mm_ystart = data->player->position->y * MAP_CELL / \
		CUBE_SIZE - MM_HEIGHT / 2;
	width_bigmmap = MAP_CELL * data->cols;
	height_bigmmap = MAP_CELL * data->rows;
	recalculate_start(data, width_bigmmap, height_bigmmap);
	draw_frame(data);
	draw_scaledminimap(data);
}
