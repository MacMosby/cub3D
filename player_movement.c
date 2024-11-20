/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:41:46 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/06 14:41:49 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void	move_forward(t_data *data)
{
	double	dX;
	double	dY;

	dX = MOVE_SPEED * cos(data->player->angle);
	dY = MOVE_SPEED * sin(data->player->angle);
	// don't forget to check for walls
	data->player->position->x += dX;
	data->player->position->y += dY;
}

void	move_backward(t_data *data)
{
	double	dX;
	double	dY;

	dX = MOVE_SPEED * cos(data->player->angle);
	dY = MOVE_SPEED * sin(data->player->angle);
	// don't forget to check for walls
	data->player->position->x -= dX;
	data->player->position->y -= dY;
}

void	turn_left(t_data *data)
{
	data->player->angle += TURN_SPEED;
	if (data->player->angle > 360)
		data->player->angle -= 360;
}

void	turn_right(t_data *data)
{
	data->player->angle -= TURN_SPEED;
	if (data->player->angle < 0)
		data->player->angle += 360;
}
