/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:28:59 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/12 11:37:38 by lde-taey         ###   ########.fr       */
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

// problem with walls in the east and south
void draw_rays(t_data *data, float x_start, float y_start)
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
	while (counter < 16)
	{
		rayX = data->player->position->x / CUBE_SIZE * MAP_CELL - x_start - 0.001f;
		rayY = data->player->position->y / CUBE_SIZE * MAP_CELL - y_start - 0.001f;
		while(1)
		{
			if (rayX < 0 || rayX >= MAP_CELL * data->cols || rayY < 0 || rayY >= MAP_CELL * data->rows)
    			break;
			rayX += cos(fovstart) * 0.5f; 
			rayY -= sin(fovstart) * 0.5f;
			if (data->map[(int)(floor((rayY + y_start - 0.001f) / MAP_CELL))][(int)(floor((rayX + x_start - 0.001f) / MAP_CELL))] == '1')
				break ;
			if (rayY > MM_HEIGHT || rayX > MM_WIDTH)
				break ;
			my_pixel_put(rayX + MM_OFFSET, rayY + MM_OFFSET, &data->imag, NEON_ORANGE);
		}
		fovstart += M_PI / 45;
		if (fovstart >= M_PI * 2)
			fovstart -= M_PI * 2;
		counter++;
	}
}

void draw_player(t_data *data, float x_start, float y_start)
{
	int pixX;
	int pixY;
	
	pixY = -1;
	while(pixY <= 1)
	{
		pixX = -1;
		while(pixX <= 1)
		{
			my_pixel_put((data->player->position->x / CUBE_SIZE * MAP_CELL + pixX + MM_OFFSET - x_start), \
				(data->player->position->y / CUBE_SIZE * MAP_CELL + pixY + MM_OFFSET - y_start), &data->imag, RED);
				pixX++;
		}
		pixY++;
	}
	draw_rays(data, x_start, y_start);
}

void	draw_scaledminimap(t_data *data, float x_start, float y_start)
{
	int i;
	int j;
	float pixX;
	float pixY;
	float scaled_x;
	float scaled_y;
	int color;

	i = 0;
	j = 0;
	while(i < data->rows)
	{
		j = 0;
		while(j < data->cols)
		{
			if (data->map[i][j] == '1')
				color = COLD_BLUE;
			else if (data->map[i][j] == '*')
				color = GREY;
			else
				color = LIGHT_BLUE;
			pixY = 0;
			while(pixY < MAP_CELL)
			{
				pixX = 0;
				while(pixX < MAP_CELL) 
				{
					scaled_x = pixX + MAP_CELL * j - x_start;
					scaled_y = pixY + MAP_CELL * i - y_start;
					
					if (scaled_x >= 0 && scaled_x < MM_WIDTH &&
   						scaled_y >= 0 && scaled_y < MM_HEIGHT)
					{
						// if (color == LIGHT_BLUE || color == COLD_BLUE)
						my_pixel_put((scaled_x + MM_OFFSET), (scaled_y + MM_OFFSET), &data->imag, color);
					}
					pixX++;
				}
				pixY++;
			}
			j++;
		}
		i++;
	}
	draw_player(data, x_start, y_start);
}

void draw_frame(t_data *data)
{
	int i;
	int j;

	i = 0;
	while(i <= MM_HEIGHT + 1)
	{
		j = 0;
		while(j <= MM_WIDTH + 1)
		{
			if (i == 0 || i == MM_HEIGHT + 1) // || j == 0 || j == data->cols + 1)
				my_pixel_put(j + MM_OFFSET - 1, i + MM_OFFSET - 1, &data->imag, METALLIC_WHITE);
			else if (j == 0 || j == MM_WIDTH + 1)
				my_pixel_put(j + MM_OFFSET - 1, i + MM_OFFSET - 1, &data->imag, METALLIC_WHITE);
			j++;
		}
		i++;
	}
}

void draw_minimap(t_data *data)
{
	float x_start;
	float y_start;
	float width_bigmmap;
	float height_bigmmap;

	x_start = data->player->position->x * MAP_CELL / CUBE_SIZE - MM_WIDTH / 2;
	y_start = data->player->position->y * MAP_CELL / CUBE_SIZE - MM_HEIGHT / 2;
	// printf("this is x_start: %f\n", x_start);
	// printf("this is y_start: %f\n", y_start);

	width_bigmmap = MAP_CELL * data->cols;
	height_bigmmap = MAP_CELL * data->rows;
	
	// problem might be that these are not precise enough for the player and rays
	if (x_start < 0)
		x_start = 0;
	else if (x_start + MM_WIDTH > width_bigmmap)
		x_start = width_bigmmap - MM_WIDTH;
	if (y_start < 0)
		y_start = 0;
	else if (y_start + MM_HEIGHT > height_bigmmap)
	{
		if (height_bigmmap < MM_HEIGHT)
			y_start = 0;
		else
			y_start = height_bigmmap - MM_HEIGHT;
	}
	// printf("this is the updated x_start: %f\n", x_start);
	// printf("this is the updated y_start: %f\n", y_start);
	draw_frame(data);
	draw_scaledminimap(data, x_start, y_start);
}

/* void	draw_minimap(t_data *data)
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
				color = COLD_BLUE;
			else if (data->map[i][j] == '*')
				color = GRASS_GREEN;
			else
				color = LIGHT_BLUE;
			pixY = MM_OFFSET;
			while(pixY < (MAP_CELL + MM_OFFSET)) // add statement here to guarantee that pixY is within scale range?
			{
				pixX = MM_OFFSET;
				while(pixX < (MAP_CELL + MM_OFFSET)) // add statement here to guarantee that pixX is within scale range?
				{
					if (color == LIGHT_BLUE || color == COLD_BLUE)
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
} */
