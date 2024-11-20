/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:55:10 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/15 17:55:11 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	build_map(t_data *data)
{
	int	**map;
	int i = 0;
	int j = 0;

	map = malloc(6 * sizeof(int *));
	while (i < 6)
	{
		map[i] = malloc(6 * sizeof(int));
		i++;
	}
	i = 0;
	while (i < 6)
	{
		while (j < 6)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < 6)
	{
		map[i][0] = 1;
		map[i][5] = 1;
		i++;
	}
	while (j < 6)
	{
		map[0][j] = 1;
		map[5][j] = 1;
		j++;
	}
	//map[4][1] = 1;
	data->map = map;
}

int	init_everything(t_data *data, char *map)
{
	t_player *player = malloc(sizeof(t_player));
	t_point		player_pos;

	data->player = player;
	data->player->angle = 45;
	data->player->position = &player_pos;
	data->player->position->x = 160;
	data->player->position->y = 224;
	data->cols = 6;
	data->rows = 6;
	build_map(data);
	parse_map(map);
	if (!init_mlx(data))
		return (1);
	/* if (!init_hooks())
		return (1);
	if (!init_render())
		return (1); */
	return (0);
}
