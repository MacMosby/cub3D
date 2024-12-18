/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_tools_frame.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:08:15 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/18 14:37:07 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_minimap_frame(t_data *data)
{
	int	i;
	int	j;

	i = 0;
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

void	draw_adjusted_height_frame(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i <= MM_WIDTH + 1)
	{
		j = 0;
		while (j <= data->rows * MAP_CELL + 1)
		{
			if (i == 0 || i == MM_WIDTH + 1)
				my_pixel_put(j + MM_OFFSET - 1, i + MM_OFFSET - 1, \
					&data->imag, METALLIC_WHITE);
			else if (j == 0 || j == data->rows * MAP_CELL + 1)
				my_pixel_put(j + MM_OFFSET - 1, i + MM_OFFSET - 1, \
					&data->imag, METALLIC_WHITE);
			j++;
		}
		i++;
	}
}

void	draw_adjusted_frame(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (MM_WIDTH > data->cols * MAP_CELL)
	{
		while (i <= data->cols * MAP_CELL + 1)
		{
			j = 0;
			while (j <= MM_HEIGHT + 1)
			{
				if (i == 0 || i == data->cols * MAP_CELL + 1)
					my_pixel_put(j + MM_OFFSET - 1, i + MM_OFFSET - 1, \
						&data->imag, METALLIC_WHITE);
				else if (j == 0 || j == MM_HEIGHT + 1)
					my_pixel_put(j + MM_OFFSET - 1, i + MM_OFFSET - 1, \
						&data->imag, METALLIC_WHITE);
				j++;
			}
			i++;
		}
	}
	else if (MM_HEIGHT > data->rows * MAP_CELL)
		draw_adjusted_height_frame(data);
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
