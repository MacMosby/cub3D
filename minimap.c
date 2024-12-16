/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:28:59 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/16 16:28:00 by lde-taey         ###   ########.fr       */
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

void	draw_small_frame(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i <= data->rows * MAP_CELL + 1)
	{
		j = 0;
		while (j <= data->cols * MAP_CELL + 1)
		{
			if (i == 0 || i == data->rows * MAP_CELL + 1)
				my_pixel_put(j + MM_OFFSET - 1, i + MM_OFFSET - 1, \
					&data->imag, METALLIC_WHITE);
			else if (j == 0 || j == data->cols * MAP_CELL + 1)
				my_pixel_put(j + MM_OFFSET - 1, i + MM_OFFSET - 1, \
					&data->imag, METALLIC_WHITE);
			j++;
		}
		i++;
	}
}

void	draw_frame(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (MM_HEIGHT > data->cols * MAP_CELL && MM_WIDTH > data->rows * MAP_CELL)
		draw_small_frame(data);
	else
	{
		while (i <= MM_HEIGHT + 1)
		{
			j = 0;
			while (j <= MM_WIDTH + 1)
			{
				if (i == 0 || i == MM_HEIGHT + 1)
					my_pixel_put(j + MM_OFFSET - 1, i + MM_OFFSET - 1, \
						&data->imag, METALLIC_WHITE);
				else if (j == 0 || j == MM_WIDTH + 1)
					my_pixel_put(j + MM_OFFSET - 1, i + MM_OFFSET - 1, \
						&data->imag, METALLIC_WHITE);
				j++;
			}
			i++;
		}
	}
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
	if (data->mm_xstart < 0)
		data->mm_xstart = 0;
	else if (data->mm_xstart + MM_WIDTH > width_bigmmap)
		data->mm_xstart = width_bigmmap - MM_WIDTH;
	if (data->mm_ystart < 0)
		data->mm_ystart = 0;
	else if (data->mm_ystart + MM_HEIGHT > height_bigmmap)
	{
		if (height_bigmmap < MM_HEIGHT)
			data->mm_ystart = 0;
		else
			data->mm_ystart = height_bigmmap - MM_HEIGHT;
	}
	draw_frame(data);
	draw_scaledminimap(data);
}
