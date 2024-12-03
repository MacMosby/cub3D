/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:28:59 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/03 15:27:42 by lde-taey         ###   ########.fr       */
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

void draw_rays(t_data *data)
{
	float rayX;
	float rayY;
	float fovstart;
	float fovend;
	int		counter;

	counter = 0;
	fovstart = (data->player->angle) * (M_PI / 180) - (FOV / 2) * (M_PI / 180);
	fovstart = ft_normalize(fovstart);
	fovend = (data->player->angle) * (M_PI / 180) + (FOV / 2) * (M_PI / 180);
	fovend = ft_normalize(fovend);
	while(counter < 16)
	{
		rayX = data->player->position->x / CUBE_SIZE * MAP_CELL;
		rayY = data->player->position->y / CUBE_SIZE * MAP_CELL;
		while(1)
		{
			if (rayX < 0 || rayX >= MAP_CELL * data->cols || rayY < 0 || rayY >= MAP_CELL * data->rows)
    			break;
			rayX += cos(fovstart) * 1.0f; 
			rayY -= sin(fovstart) * 1.0f;
			if (data->map[(int)(rayY / MAP_CELL)][(int)(rayX / MAP_CELL)] == '1')
				break ;
			// mlx_pixel_put(data->mlx_ptr_map, data->win_ptr_map, rayX, rayY, 0xFF13F0);
			my_pixel_put(rayX, rayY, &data->imag, 0xFF13F0);
		}
		fovstart += M_PI / 45;
		if (fovstart >= M_PI * 2)
			fovstart -= M_PI * 2;
		counter++;
	}
}

void draw_player(t_data *data)
{
	int pixX;
	int pixY;
	
	pixY = -2;
	while(pixY < 2)
	{
		pixX = -2;
		while(pixX < 2)
		{
			// mlx_pixel_put(data->mlx_ptr_map, data->win_ptr_map, (data->player->position->x / CUBE_SIZE * MAP_CELL + pixX), (data->player->position->y / CUBE_SIZE * MAP_CELL + pixY), 0xFF0000);
			my_pixel_put((data->player->position->x / CUBE_SIZE * MAP_CELL + pixX), (data->player->position->y / CUBE_SIZE * MAP_CELL + pixY), &data->imag, 0xFF0000);
				pixX++;
		}
		pixY++;
	}
	draw_rays(data);
}

void	draw_minimap(t_data *data)
{
	int i;
	int j;
	int pixX;
	int pixY;
	int color;

	i = 0;
	j = 0;
	while(i < data->rows)
	{
		j = 0;
		while(j < data->cols)
		{
			if (data->map[i][j] == '1')
				color = 0x0033CC;
			else if (data->map[i][j] == '*')
				color = 0x77DD77;
			else
				color = 0x33FFE6;
			pixY = 0;
			while(pixY < MAP_CELL)
			{
				pixX = 0;
				while(pixX < MAP_CELL)
				{
					// mlx_pixel_put(data->mlx_ptr_map, data->win_ptr_map, (MAP_CELL * j + pixX), (MAP_CELL * i + pixY), color);
					my_pixel_put((MAP_CELL * j + pixX), (MAP_CELL * i + pixY), &data->imag, color);
					pixX++;
				}
				pixY++;
			}
			j++;
		}
		i++;
	}
	draw_player(data);
}

// void init_minimap(t_data *data)
// {
// 	int map_width;
// 	int map_height;

// 	map_width = data->cols * MAP_CELL;
// 	map_height = data->rows * MAP_CELL;
// 	data->mlx_ptr_map = mlx_init();
// 	if (!data->mlx_ptr_map)
// 		printf("Something went wrong with map mlx init\n");
// 	data->win_ptr_map = mlx_new_window(data->mlx_ptr_map, map_width, map_height, "minimap");
// 	if (!data->win_ptr_map)
// 	 	printf("Something went wrong with map mlx new window\n");
// 	draw_minimap(data);
// 	mlx_hook(data->win_ptr_map, 17, 1L << 17, close_window, &data);
// }
