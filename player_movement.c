/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:41:46 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/03 17:25:57 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_pos_valid(t_data *data, double dX, double dY)
{
	t_point	point;
	t_point	grid;

	point.x = data->player->position->x + dX;
	point.y = data->player->position->y + dY;
	grid = get_grid_position(point);
	if (data->map[(int)grid.y][(int)grid.x] == '1')
		return (0);
	point.x -= dX;
	grid = get_grid_position(point);
	if (data->map[(int)grid.y][(int)grid.x] != '1')
		return (1);
	point.x += dX;
	point.y -= dY;
	grid = get_grid_position(point);
	if (data->map[(int)grid.y][(int)grid.x] != '1')
		return (1);
	return (0);
}

void	move_forward(t_data *data)
{
	double	dx;
	double	dy;

	dx = 0;
	dy = 0;
	if (data->player->angle == 0)
		dx = 1 * MOVE_SPEED;
	else if (data->player->angle == 90)
		dy = 1 * MOVE_SPEED;
	else if (data->player->angle == 180)
		dx = -1 * MOVE_SPEED;
	else if (data->player->angle == 270)
		dy = -1 * MOVE_SPEED;
	else
	{
		dx = MOVE_SPEED * cos(data->player->angle / (double)180 * M_PI);
		dy = MOVE_SPEED * sin(data->player->angle / (double)180 * M_PI);
	}
	if (is_pos_valid(data, dx, -1 * dy))
	{
		data->player->position->x += dx;
		data->player->position->y -= dy;
		render(data);
	}
}

void	move_backward(t_data *data)
{
	double	dx;
	double	dy;

	dx = 0;
	dy = 0;
	if (data->player->angle == 0)
		dx = 1 * MOVE_SPEED;
	else if (data->player->angle == 90)
		dy = 1 * MOVE_SPEED;
	else if (data->player->angle == 180)
		dx = -1 * MOVE_SPEED;
	else if (data->player->angle == 270)
		dy = -1 * MOVE_SPEED;
	else
	{
		dx = MOVE_SPEED * cos(data->player->angle / (double)180 * M_PI);
		dy = MOVE_SPEED * sin(data->player->angle / (double)180 * M_PI);
	}
	if (is_pos_valid(data, -1 * dx, dy))
	{
		data->player->position->x -= dx;
		data->player->position->y += dy;
		render(data);
	}
}

void	move_left(t_data *data, double dx, double dy)
{
	double	angle;

	angle = data->player->angle + 90;
	if (angle >= 360)
		angle -= 360;
	if (angle == 0)
		dx = 1 * MOVE_SPEED;
	else if (angle == 90)
		dy = 1 * MOVE_SPEED;
	else if (angle == 180)
		dx = -1 * MOVE_SPEED;
	else if (angle == 270)
		dy = -1 * MOVE_SPEED;
	else
	{
		dx = MOVE_SPEED * cos(angle / (double)180 * M_PI);
		dy = MOVE_SPEED * sin(angle / (double)180 * M_PI);
	}
	if (is_pos_valid(data, dx, -1 * dy))
	{
		data->player->position->x += dx;
		data->player->position->y -= dy;
		render(data);
	}
}

void	move_right(t_data *data, double dx, double dy)
{
	double	angle;

	angle = data->player->angle - 90;
	if (angle < 0)
		angle += 360;
	if (angle == 0)
		dx = 1 * MOVE_SPEED;
	else if (angle == 90)
		dy = 1 * MOVE_SPEED;
	else if (angle == 180)
		dx = -1 * MOVE_SPEED;
	else if (angle == 270)
		dy = -1 * MOVE_SPEED;
	else
	{
		dx = MOVE_SPEED * cos(angle / (double)180 * M_PI);
		dy = MOVE_SPEED * sin(angle / (double)180 * M_PI);
	}
	if (is_pos_valid(data, dx, -1 * dy))
	{
		data->player->position->x += dx;
		data->player->position->y -= dy;
		render(data);
	}
}
