/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_turns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:59:31 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/12 12:59:33 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	turn_left(t_data *data)
{
	printf("turn left\n");
	data->player->angle += TURN_SPEED;
	if (data->player->angle >= 360)
		data->player->angle -= 360;
	render(data);
}

void	turn_right(t_data *data)
{
	printf("turn right\n");
	data->player->angle -= TURN_SPEED;
	if (data->player->angle < 0)
		data->player->angle += 360;
	render(data);
}
