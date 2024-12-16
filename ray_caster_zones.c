/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster_zones.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:42:56 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/12 16:42:59 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ne_cast_ray(t_data *data, double plane_angle, double v_angle, int col)
{
	t_point	hori_p;
	t_point	vert_p;
	double	vert_dist;
	double	hori_dist;
	double	real_dist;

	hori_p = find_horizontal_wall(data, v_angle, NE, &hori_dist);
	vert_p = find_vertical_wall(data, v_angle, NE, &vert_dist);
	real_dist = get_correct_distance(hori_dist, vert_dist, plane_angle);
	if (hori_dist < 0)
	{
		data->wall = E;
		cast_slice(data, real_dist, col, (int)floor(vert_p.y) % CUBE_SIZE);
	}
	else if (vert_dist < 0 || hori_dist < vert_dist)
	{
		data->wall = N;
		cast_slice(data, real_dist, col, (int)floor(hori_p.x) % CUBE_SIZE);
	}
	else
	{
		data->wall = E;
		cast_slice(data, real_dist, col, (int)floor(vert_p.y) % CUBE_SIZE);
	}
}

void	nw_cast_ray(t_data *data, double plane_angle, double v_angle, int col)
{
	t_point	hori_p;
	t_point	vert_p;
	double	vert_dist;
	double	hori_dist;
	double	real_dist;

	hori_p = find_horizontal_wall(data, v_angle, NW, &hori_dist);
	vert_p = find_vertical_wall(data, v_angle, NW, &vert_dist);
	real_dist = get_correct_distance(hori_dist, vert_dist, plane_angle);
	data->wall = W;
	if (hori_dist < 0)
		cast_slice(data, real_dist, col, CUBE_SIZE - 1
			- ((int)floor(vert_p.y) % CUBE_SIZE));
	else if (vert_dist < 0 || hori_dist < vert_dist)
	{
		data->wall = N;
		cast_slice(data, real_dist, col, (int)floor(hori_p.x) % CUBE_SIZE);
	}
	else
		cast_slice(data, real_dist, col, CUBE_SIZE - 1
			- ((int)floor(vert_p.y) % CUBE_SIZE));
}

void	sw_cast_ray(t_data *data, double plane_angle, double v_angle, int col)
{
	t_point	hori_p;
	t_point	vert_p;
	double	vert_dist;
	double	hori_dist;
	double	real_dist;

	hori_p = find_horizontal_wall(data, v_angle, SW, &hori_dist);
	vert_p = find_vertical_wall(data, v_angle, SW, &vert_dist);
	real_dist = get_correct_distance(hori_dist, vert_dist, plane_angle);
	data->wall = W;
	if (hori_dist < 0)
		cast_slice(data, real_dist, col, CUBE_SIZE - 1
			- ((int)floor(vert_p.y) % CUBE_SIZE));
	else if (vert_dist < 0 || hori_dist < vert_dist)
	{
		data->wall = S;
		cast_slice(data, real_dist, col, CUBE_SIZE - 1
			- ((int)floor(hori_p.x) % CUBE_SIZE));
	}
	else
		cast_slice(data, real_dist, col, CUBE_SIZE - 1
			- ((int)floor(vert_p.y) % CUBE_SIZE));
}

void	se_cast_ray(t_data *data, double plane_angle, double v_angle, int col)
{
	t_point	hori_p;
	t_point	vert_p;
	double	vert_dist;
	double	hori_dist;
	double	real_dist;

	hori_p = find_horizontal_wall(data, v_angle, SE, &hori_dist);
	vert_p = find_vertical_wall(data, v_angle, SE, &vert_dist);
	real_dist = get_correct_distance(hori_dist, vert_dist, plane_angle);
	if (hori_dist < 0)
	{
		data->wall = E;
		cast_slice(data, real_dist, col, (int)floor(vert_p.y) % CUBE_SIZE);
	}
	else if (vert_dist < 0 || hori_dist < vert_dist)
	{
		data->wall = S;
		cast_slice(data, real_dist, col, CUBE_SIZE - 1
			- ((int)floor(hori_p.x) % CUBE_SIZE));
	}
	else
	{
		data->wall = E;
		cast_slice(data, real_dist, col, (int)floor(vert_p.y) % CUBE_SIZE);
	}
}
