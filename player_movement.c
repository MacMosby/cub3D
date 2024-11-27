/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:41:46 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/25 15:11:14 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int	is_pos_valid(t_data *data, double pos_x, double pos_y)
{
	int	grid_x;
	int	grid_y;

	grid_x = floor(pos_x / (double)CUBE_SIZE);
	grid_y = floor(pos_y / (double)CUBE_SIZE);

	if (data->map[grid_y][grid_x] != '1')
		return (1);
	else
		return (0);
}

void	move_forward(t_data *data)
{
	double	dX;
	double	dY;

	dX = 0;
	dY = 0;
	printf("move forward\n");
	if (data->player->angle == 0)
		dX = 1 * MOVE_SPEED;
	else if (data->player->angle == 90)
		dY = 1 * MOVE_SPEED;
	else if (data->player->angle == 180)
		dX = -1 * MOVE_SPEED;
	else if (data->player->angle == 270)
		dY = -1 * MOVE_SPEED;
	else
	{
		dX = MOVE_SPEED * cos(data->player->angle / (double)180 * M_PI);
		dY = MOVE_SPEED * sin(data->player->angle / (double)180 * M_PI);
	}
	printf("dY: %f\n", dY);
	// don't forget to check for walls
	if (is_pos_valid(data, data->player->position->x + dX, data->player->position->y - dY))
	{
		data->player->position->x += dX;
		data->player->position->y -= dY;
		ray_caster(data);
	}
}

void	move_backward(t_data *data)
{
	double	dX;
	double	dY;

	dX = 0;
	dY = 0;
	printf("move backward\n");
	if (data->player->angle == 0)
		dX = 1 * MOVE_SPEED;
	else if (data->player->angle == 90)
		dY = 1 * MOVE_SPEED;
	else if (data->player->angle == 180)
		dX = -1 * MOVE_SPEED;
	else if (data->player->angle == 270)
		dY = -1 * MOVE_SPEED;
	else
	{
		dX = MOVE_SPEED * cos(data->player->angle / (double)180 * M_PI);
		dY = MOVE_SPEED * sin(data->player->angle / (double)180 * M_PI);
	}
	printf("dY: %f\n", dY);
	// don't forget to check for walls
	if (is_pos_valid(data, data->player->position->x - dX, data->player->position->y + dY))
	{
		data->player->position->x -= dX;
		data->player->position->y += dY;
		ray_caster(data);
	}
}

void	move_left(t_data *data)
{
	double	dX;
	double	dY;
	double	angle;

	angle = data->player->angle + 90;
	if (angle > 360)
		angle -= 360;
	dX = 0;
	dY = 0;
	printf("move left\n");
	if (angle == 0)
		dX = 1 * MOVE_SPEED;
	else if (angle == 90)
		dY = 1 * MOVE_SPEED;
	else if (angle == 180)
		dX = -1 * MOVE_SPEED;
	else if (angle == 270)
		dY = -1 * MOVE_SPEED;
	else
	{
		dX = MOVE_SPEED * cos(angle / (double)180 * M_PI);
		dY = MOVE_SPEED * sin(angle / (double)180 * M_PI);
	}
	// don't forget to check for walls
	if (is_pos_valid(data, data->player->position->x + dX, data->player->position->y - dY))
	{
		data->player->position->x += dX;
		data->player->position->y -= dY;
		ray_caster(data);
	}
}

void	move_right(t_data *data)
{
	double	dX;
	double	dY;
	double	angle;

	angle = data->player->angle - 90;
	if (angle < 0)
		angle += 360;
	dX = 0;
	dY = 0;
	printf("move right\n");
	if (angle == 0)
		dX = 1 * MOVE_SPEED;
	else if (angle == 90)
		dY = 1 * MOVE_SPEED;
	else if (angle == 180)
		dX = -1 * MOVE_SPEED;
	else if (angle == 270)
		dY = -1 * MOVE_SPEED;
	else
	{
		dX = MOVE_SPEED * cos(angle / (double)180 * M_PI);
		dY = MOVE_SPEED * sin(angle / (double)180 * M_PI);
	}
	// don't forget to check for walls
	if (is_pos_valid(data, data->player->position->x + dX, data->player->position->y - dY))
	{
		data->player->position->x += dX;
		data->player->position->y -= dY;
		ray_caster(data);
	}
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
