/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:41:46 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/29 15:38:55 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int	is_pos_valid(t_data *data, double dX, double dY)
{
	t_point point;
	t_point grid;

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
	if (is_pos_valid(data, dX, -1 * dY))
	{
		data->player->position->x += dX;
		data->player->position->y -= dY;
		ray_caster(data);
		draw_minimap(data);
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
	if (is_pos_valid(data, -1 * dX, dY))
	{
		data->player->position->x -= dX;
		data->player->position->y += dY;
		ray_caster(data);
		draw_minimap(data);
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
	if (is_pos_valid(data, dX, -1 * dY))
	{
		data->player->position->x += dX;
		data->player->position->y -= dY;
		ray_caster(data);
		draw_minimap(data);
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
	if (is_pos_valid(data, dX, -1 * dY))
	{
		data->player->position->x += dX;
		data->player->position->y -= dY;
		ray_caster(data);
		draw_minimap(data);
	}
}

void	turn_left(t_data *data)
{
	printf("turn left\n");
	data->player->angle += TURN_SPEED;
	if (data->player->angle > 360)
		data->player->angle -= 360;
	ray_caster(data);
	draw_minimap(data);
}

void	turn_right(t_data *data)
{
	printf("turn right\n");
	data->player->angle -= TURN_SPEED;
	if (data->player->angle < 0)
		data->player->angle += 360;
	ray_caster(data);
	draw_minimap(data);
}
