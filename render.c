/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:57:57 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/03 17:22:31 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void my_pixel_put(int x, int y, t_imag *imag, int color)
{
	int	position;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		position = (y * imag->line_len)	+ (x * imag->bpp / 8);
		*(unsigned int*)(imag->pixels_ptr + position) = color;
	}
}

void render(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ray_caster(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imag.img_ptr, 0, 0);
}