/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:57:57 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/03 16:03:28 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void paint_background(t_data *data)
{
	int i;
	int j;

	i = 0;
	while(i < HEIGTH)
	{
		j = 0;
		while(j < WIDTH)
		{
			my_pixel_put(j, i, &data->imag, 0xFF7F80);
			j++;
		}
		i++;
	}
}

void my_pixel_put(int x, int y, t_imag *imag, int color)
{
	int	position;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGTH))
	{
		position = (y * imag->line_len)	+ (x * imag->bpp / 8);
		*(unsigned int*)(imag->pixels_ptr + position) = color;
	}
}

void render(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	// handle all the different pixels
	// 0. background first?
	paint_background(data);
	// 1. maze
	ray_caster(data);
	// 2. minimap
	draw_minimap(data);
	// 4. drag whole thing with defined pixels into window
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imag.img_ptr, 0, 0);
}