/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster_axis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:42:49 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/12 16:42:50 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	n_cast_ray(t_data *data, double plane_angle, double v_angle, int col)
{
	t_point	hori_p;
	double	hori_dist;
	double	real_dist;
	int		offset;

	hori_p = find_horizontal_wall(data, v_angle, N, &hori_dist);
	real_dist = hori_dist * cos(plane_angle / (double)180 * M_PI);
	offset = (int)floor(hori_p.x) % CUBE_SIZE;
	data->wall = N;
	cast_slice(data, real_dist, col, offset);
}

void	s_cast_ray(t_data *data, double plane_angle, double v_angle, int col)
{
	t_point	hori_p;
	double	hori_dist;
	double	real_dist;
	int		offset;

	hori_p = find_horizontal_wall(data, v_angle, S, &hori_dist);
	real_dist = hori_dist * cos(plane_angle / (double)180 * M_PI);
	offset = CUBE_SIZE - 1 - ((int)floor(hori_p.x) % CUBE_SIZE);
	data->wall = S;
	cast_slice(data, real_dist, col, offset);
}

void	e_cast_ray(t_data *data, double plane_angle, double v_angle, int col)
{
	t_point	vert_p;
	double	vert_dist;
	double	real_dist;
	int		offset;

	vert_p = find_vertical_wall(data, v_angle, E, &vert_dist);
	real_dist = vert_dist * cos(plane_angle / (double)180 * M_PI);
	offset = (int)floor(vert_p.y) % CUBE_SIZE;
	data->wall = E;
	cast_slice(data, real_dist, col, offset);
}

void	w_cast_ray(t_data *data, double plane_angle, double v_angle, int col)
{
	t_point	vert_p;
	double	vert_dist;
	double	real_dist;
	int		offset;

	vert_p = find_vertical_wall(data, v_angle, W, &vert_dist);
	real_dist = vert_dist * cos(plane_angle / (double)180 * M_PI);
	offset = CUBE_SIZE - 1 - ((int)floor(vert_p.y) % CUBE_SIZE);
	data->wall = W;
	cast_slice(data, real_dist, col, offset);
}
