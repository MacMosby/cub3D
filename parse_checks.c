/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:08:14 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/26 12:33:54 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void space_check(t_data *data)
{
	int i;
	int j;

	i = 0;
	while(data->map[i] != NULL)
	{
		j = 0;
		while(data->map[i][j] != '\0')
		{
			if (data->map[i][j] == ' ')
				data->map[i][j] = '*';
			j++;
		}
		i++;
	}
}

void player_check(t_data *data, int fd)
{
	int i;
	int j;
	int player;

	i = 0;
	player = 0;
	while(data->map[i] != NULL)
	{
		j = 0;
		while(data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E' || data->map[i][j] == 'S' || data->map[i][j] == 'W')
			{
				data->player->position->x = j * CUBE_SIZE + CUBE_SIZE/2; // where is the null center in the map?
				data->player->position->y = i * CUBE_SIZE + CUBE_SIZE/2;
				if (data->map[i][j] == 'N')
					data->player->angle = 90;
				else if (data->map[i][j] == 'E')
					data->player->angle = 0;
				else if (data->map[i][j] == 'S')
					data->player->angle = 270;
				else if (data->map[i][j] == 'W')
					data->player->angle = 180;
				player++;
			}
			j++;
		}
		i++;
	}
	if (player == 0)
	{
		printf("No player found.");
		map_error(fd);
	}
	else if (player > 1)
	{
		printf("More than one player found.");
		map_error(fd);
	}
}