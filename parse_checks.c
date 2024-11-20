/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:08:14 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/19 15:54:35 by lde-taey         ###   ########.fr       */
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
				// data->player_pos.x = i;
				// data->player_pos.y = j;
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