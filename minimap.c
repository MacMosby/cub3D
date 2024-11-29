/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:28:59 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/29 14:58:34 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float normalize_angle(float angle)
{
	if(angle < 0)
		angle = angle + 2 * M_PI;
	else if (angle > 2 * M_PI)
		angle = angle - 2 * M_PI;
	return (angle);
}

// turns are in the wrong direction
// debug with statements
void draw_rays(t_data *data)
{
	float rayX;
	float rayY;
	float fovstart;
	float fovend;

	fovstart = (data->player->angle) * (M_PI / 180) - (FOV / 2) * (M_PI / 180);
	fovend = (data->player->angle) * (M_PI / 180) + (FOV / 2) * (M_PI / 180);
	while(fovstart < fovend)
	{
		rayX = data->player->position->x / CUBE_SIZE * MAP_CELL - 0.5;
		rayY = data->player->position->y / CUBE_SIZE * MAP_CELL - 0.5;
		// printf("This is rayX: %f\n", rayX);
		// printf("This is rayY: %f\n", rayY);
		while(1)
		{
			if (rayX < 0 || rayX >= MAP_CELL * data->cols || rayY < 0 || rayY >= MAP_CELL * data->rows)
    			break;
			rayX += cos(fovstart) * 1.0f; 
			rayY -= sin(fovstart) * 1.0f;
			if (data->map[(int)(rayY / MAP_CELL)][(int)(rayX / MAP_CELL)] == '1')
				break ;
			mlx_pixel_put(data->mlx_ptr_map, data->win_ptr_map, rayX, rayY, 0xFF13F0);
		}
		// printf("This is rayX after the while loop: %f\n", rayX);
		// printf("This is rayY after the while loop: %f\n", rayY);
		fovstart += M_PI / 45;
		if (fovstart >= M_PI * 2)
			fovstart -= M_PI * 2;
	}
}

void draw_player(t_data *data)
{
	int pixX;
	int pixY;
	
	pixY = -4;
	while(pixY < 4)
	{
		pixX = -4;
		while(pixX < 4)
		{
			mlx_pixel_put(data->mlx_ptr_map, data->win_ptr_map, (data->player->position->x / CUBE_SIZE * MAP_CELL + pixX), (data->player->position->y / CUBE_SIZE * MAP_CELL + pixY), 0xFF0000);
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
					mlx_pixel_put(data->mlx_ptr_map, data->win_ptr_map, (MAP_CELL * j + pixX), (MAP_CELL * i + pixY), color);
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

void init_minimap(t_data *data)
{
	int map_width;
	int map_height;

	map_width = data->cols * MAP_CELL;
	map_height = data->rows * MAP_CELL;
	data->mlx_ptr_map = mlx_init();
	if (!data->mlx_ptr_map)
		printf("Something went wrong with map mlx init\n");
	data->win_ptr_map = mlx_new_window(data->mlx_ptr_map, map_width, map_height, "minimap");
	if (!data->win_ptr_map)
	 	printf("Something went wrong with map mlx new window\n");
	draw_minimap(data);
	mlx_hook(data->win_ptr_map, 17, 1L << 17, close_window, &data);
}
