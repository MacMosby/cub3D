/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:17:25 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/16 16:17:58 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_values(t_data *data)
{
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
	data->map = NULL;
	data->mlx_ptr = NULL;
	data->mm_xstart = 0;
	data->mm_ystart = 0;
}

void	init_struct(t_data *data)
{
	t_player	*player;
	t_point		*player_pos;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		printf("Error. \nMalloc failed\n");
		exit(EXIT_FAILURE);
	}
	player_pos = malloc(sizeof(t_point));
	if (!player_pos)
	{
		printf("Error. \nMalloc failed\n");
		free(player);
		exit(EXIT_FAILURE);
	}
	data->player = player;
	data->player->angle = 0.0;
	data->player->position = player_pos;
	data->player->position->x = 0.0;
	data->player->position->y = 0.0;
	init_values(data);
}

int	init_everything(char *input, t_data *data)
{
	init_struct(data);
	parse_input(input, data);
	if (!init_mlx(data))
		return (1);
	return (0);
}
