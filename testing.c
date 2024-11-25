/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:39:29 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/25 14:57:08 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void print_map(t_data *data)
{
	printf("\n\nHere is the map\n\n\n");
	int i = 0;
	while(data->map[i] != NULL)
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	printf("\n\n");
}

void print_struct(t_data *data)
{
	printf("This is the position of the player: \nx = %f\ny = %f\n", data->player->position->x, data->player->position->y);
	printf("\n\nThis is the path to the west texture: %s\n", data->we);
	printf("This is the path to the north texture: %s\n", data->no);
	printf("This is the path to the south texture: %s\n", data->so);	
	printf("This is the path to the east texture: %s\n\n", data->ea);
	printf("These are the colors of the floor: %i, %i, %i\n", data->c_floor.r, data->c_floor.g, data->c_floor.b);
	printf("This is the hexadecimal for the floor: %li\n", data->c_floor.hexa);
	printf("These are the colors of the ceiling: %i, %i, %i\n", data->c_ceiling.r, data->c_ceiling.g, data->c_ceiling.b);
	printf("This is the hexadecimal for the ceiling: %li\n\n", data->c_ceiling.hexa);
	printf("This is the position of the player: \nx = %f\ny = %f\n", data->player->position->x, data->player->position->y);
	printf("This is the current orientation of the player:\n%f\n\n\n", data->player->angle);
}