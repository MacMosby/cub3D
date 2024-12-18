/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:19:13 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/18 14:02:00 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	ft_normalize(float angle)
{
	if (angle > M_PI * 2)
		angle -= M_PI * 2;
	else if (angle < 0)
		angle += M_PI * 2;
	return (angle);
}

void	calculate_and_put_ray(t_data *data, float fovstart)
{
	float	rayx;
	float	rayy;

	rayx = data->player->position->x / CUBE_SIZE * \
			MAP_CELL - data->mm_xstart - 0.001f;
	rayy = data->player->position->y / CUBE_SIZE * \
		MAP_CELL - data->mm_ystart - 0.001f;
	while (1)
	{
		if (rayx < 0 || rayx >= MAP_CELL * data->cols \
			|| rayy < 0 || rayy >= MAP_CELL * data->rows)
			break ;
		rayx += cos(fovstart) * 0.5f; 
		rayy -= sin(fovstart) * 0.5f;
		if (data->map[(int)(floor((rayy + data->mm_ystart - 0.001f) \
			/ MAP_CELL))][(int)(floor((rayx + data->mm_xstart - 0.001f) \
			/ MAP_CELL))] == '1')
			break ;
		if (rayy > MM_HEIGHT || rayx > MM_WIDTH)
			break ;
		my_pixel_put(rayx + MM_OFFSET, rayy + MM_OFFSET, \
			&data->imag, NEON_ORANGE);
	}
}

void	draw_rays(t_data *data)
{
	float	fovstart;
	int		counter;

	counter = 0;
	fovstart = (data->player->angle) * (M_PI / 180) - (FOV / 2) * (M_PI / 180);
	fovstart = ft_normalize(fovstart);
	while (counter < 16)
	{
		calculate_and_put_ray(data, fovstart);
		fovstart += M_PI / 45;
		if (fovstart >= M_PI * 2)
			fovstart -= M_PI * 2;
		counter++;
	}
}

void	draw_player(t_data *data)
{
	int	pixx;
	int	pixy;

	pixy = -1;
	while (pixy <= 1)
	{
		pixx = -1;
		while (pixx <= 1)
		{
			my_pixel_put((data->player->position->x / CUBE_SIZE * MAP_CELL \
				+ pixx + MM_OFFSET - data->mm_xstart), \
				(data->player->position->y / CUBE_SIZE * MAP_CELL + pixy + \
				MM_OFFSET - data->mm_ystart), &data->imag, RED);
			pixx++;
		}
		pixy++;
	}
	draw_rays(data);
}

void	recalculate_start(t_data *data, float width_bigmm, float height_bigmm)
{
	if (data->mm_xstart < 0)
		data->mm_xstart = 0;
	else if (data->mm_xstart + MM_WIDTH > width_bigmm)
	{
		if (width_bigmm < MM_WIDTH)
			data->mm_xstart = 0;
		else
			data->mm_xstart = width_bigmm - MM_WIDTH;
	}
	if (data->mm_ystart < 0)
		data->mm_ystart = 0;
	else if (data->mm_ystart + MM_HEIGHT > height_bigmm)
	{
		if (height_bigmm < MM_HEIGHT)
			data->mm_ystart = 0;
		else
			data->mm_ystart = height_bigmm - MM_HEIGHT;
	}
}
