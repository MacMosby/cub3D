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

	printf("move forward\n");
	if (data->player->angle == 0)
	{
		dX = 1;
		dY = 0;
	}
	else if (data->player->angle == 90)
	{
		dX = 0;
		dY = 1;
	}
	else if (data->player->angle == 180)
	{
		dX = -1;
		dY = 0;
	}
	else if (data->player->angle == 270)
	{
		dX = 0;
		dY = -1;
	}
	else
	{
		dX = MOVE_SPEED * cos(data->player->angle / (double)180 * M_PI);
		dY = MOVE_SPEED * sin(data->player->angle / (double)180 * M_PI);
	}
	printf("dY: %f\n", dY);
	// don't forget to check for walls
	data->player->position->x += dX;
	data->player->position->y += dY;
	ray_caster(data);
}

void	move_backward(t_data *data)
{
	double	dX;
	double	dY;

	printf("move backward\n");
	dX = MOVE_SPEED * cos(data->player->angle / (double)180 * M_PI);
	//dX = 0;
	dY = MOVE_SPEED * sin(data->player->angle / (double)180 * M_PI);
	//dY = 0;
	printf("dY: %f\n", dY);
	// don't forget to check for walls
	data->player->position->x -= dX;
	data->player->position->y -= dY;
	ray_caster(data);
}

void	move_left(t_data *data)
{
	double	dX;
	double	dY;
	double	angle;

	printf("move left\n");
	angle = data->player->angle + 90;
	if (angle > 360)
		angle -= 360;
	dX = MOVE_SPEED * cos(angle / (double)180 * M_PI);
	dY = MOVE_SPEED * sin(angle / (double)180 * M_PI);
	// don't forget to check for walls
	data->player->position->x += dX;
	data->player->position->y += dY;
	ray_caster(data);
}

void	move_right(t_data *data)
{
	double	dX;
	double	dY;
	double	angle;

	printf("move right\n");
	angle = data->player->angle - 90;
	if (angle < 0)
		angle += 360;
	dX = MOVE_SPEED * cos(angle / (double)180 * M_PI);
	dY = MOVE_SPEED * sin(angle / (double)180 * M_PI);
	// don't forget to check for walls
	data->player->position->x += dX;
	data->player->position->y += dY;
	ray_caster(data);
}

void	turn_left(t_data *data)
{
	printf("turn left\n");
	data->player->angle += TURN_SPEED;
	if (data->player->angle > 360)
		data->player->angle -= 360;
	ray_caster(data);
}

void	turn_right(t_data *data)
{
	printf("turn right\n");
	data->player->angle -= TURN_SPEED;
	if (data->player->angle < 0)
		data->player->angle += 360;
	ray_caster(data);
}
