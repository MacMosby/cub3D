/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:17:25 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/22 12:54:33 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* void	build_map(t_data *data)
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
} */

void init_struct(t_data *data)
{
	t_player	*player = malloc(sizeof(t_player));
	t_point		player_pos;

	data->player = player;
	data->player->angle = 0;
	data->player->position = &player_pos;
	data->player->position->x = 0; 
	data->player->position->y = 0;

	data->ea = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->c_ceiling.r = 0;
	data->c_ceiling.g = 0;
	data->c_ceiling.b = 0;
	data->c_ceiling.full = 0;
	data->c_ceiling.hexa = 0;
	data->c_floor.r = 0;
	data->c_floor.g = 0;
	data->c_floor.b = 0;
	data->c_floor.full = 0;
	data->c_floor.hexa = 0;
	data->cols = 0;
	data->rows = 0;
}

int	init_everything(char *input, t_data *data)
{
	init_struct(data);
	parse_input(input, data);
	// if (!init_mlx(data))
	// 	return (1);
	return (0);
}
