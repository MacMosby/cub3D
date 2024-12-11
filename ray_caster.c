/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:03:02 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/04 13:39:37 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ne_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	t_point	hori_p;
	t_point	vert_p;
	double	vert_dist;
	double	hori_dist;
	double	real_dist;
	int		offset;

	hori_p = find_horizontal_wall(data, viewing_angle, NE, &hori_dist);
	vert_p = find_vertical_wall(data, viewing_angle, NE, &vert_dist);
	real_dist = get_correct_distance(hori_dist, vert_dist, plane_angle);
	if (hori_dist < 0)
		offset = (int)floor(vert_p.y) % CUBE_SIZE;
	else if (vert_dist < 0)
		offset = (int)floor(hori_p.x) % CUBE_SIZE;
	else if (hori_dist < vert_dist)
		offset = (int)floor(hori_p.x) % CUBE_SIZE;
	else
		offset = (int)floor(vert_p.y) % CUBE_SIZE;
	cast_slice(data, real_dist, col, offset);
}

void	nw_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	t_point	hori_p;
	t_point	vert_p;
	double	vert_dist;
	double	hori_dist;
	double	real_dist;
	int		offset;

	hori_p = find_horizontal_wall(data, viewing_angle, NW, &hori_dist);
	vert_p = find_vertical_wall(data, viewing_angle, NW, &vert_dist);
	real_dist = get_correct_distance(hori_dist, vert_dist, plane_angle);
	if (hori_dist < 0)
		offset = CUBE_SIZE - 1 - ((int)floor(vert_p.y) % CUBE_SIZE);
	else if (vert_dist < 0)
		offset = (int)floor(hori_p.x) % CUBE_SIZE;
	else if (hori_dist < vert_dist)
		offset = (int)floor(hori_p.x) % CUBE_SIZE;
	else
		offset = CUBE_SIZE - 1 - ((int)floor(vert_p.y) % CUBE_SIZE);
	cast_slice(data, real_dist, col, offset);
}

void	sw_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	t_point	hori_p;
	t_point	vert_p;
	double	vert_dist;
	double	hori_dist;
	double	real_dist;
	int		offset;

	hori_p = find_horizontal_wall(data, viewing_angle, SW, &hori_dist);
	vert_p = find_vertical_wall(data, viewing_angle, SW, &vert_dist);
	real_dist = get_correct_distance(hori_dist, vert_dist, plane_angle);
	if (hori_dist < 0)
		offset = CUBE_SIZE - 1 - ((int)floor(vert_p.y) % CUBE_SIZE);
	else if (vert_dist < 0)
		offset = CUBE_SIZE - 1 - ((int)floor(hori_p.x) % CUBE_SIZE);
	else if (hori_dist < vert_dist)
		offset = CUBE_SIZE - 1 - ((int)floor(hori_p.x) % CUBE_SIZE);
	else
		offset = CUBE_SIZE - 1 - ((int)floor(vert_p.y) % CUBE_SIZE);
	cast_slice(data, real_dist, col, offset);
}

void	se_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	t_point	hori_p;
	t_point	vert_p;
	double	vert_dist;
	double	hori_dist;
	double	real_dist;
	int		offset;

	hori_p = find_horizontal_wall(data, viewing_angle, SE, &hori_dist);
	vert_p = find_vertical_wall(data, viewing_angle, SE, &vert_dist);
	real_dist = get_correct_distance(hori_dist, vert_dist, plane_angle);
	if (hori_dist < 0)
		offset = (int)floor(vert_p.y) % CUBE_SIZE;
	else if (vert_dist < 0)
		offset = CUBE_SIZE - 1 - ((int)floor(hori_p.x) % CUBE_SIZE);
	else if (hori_dist < vert_dist)
		offset = CUBE_SIZE - 1 - ((int)floor(hori_p.x) % CUBE_SIZE);
	else
		offset = (int)floor(vert_p.y) % CUBE_SIZE;
	cast_slice(data, real_dist, col, offset);
}

void	n_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	t_point	hori_p;
	double	hori_dist;
	double	real_dist;
	int		offset;

	hori_p = find_horizontal_wall(data, viewing_angle, N, &hori_dist);
	real_dist = hori_dist * cos(plane_angle / (double)180 * M_PI);
	offset = (int)floor(hori_p.x) % CUBE_SIZE;
	cast_slice(data, real_dist, col, offset);
}

void	s_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	t_point	hori_p;
	double	hori_dist;
	double	real_dist;
	int		offset;

	hori_p = find_horizontal_wall(data, viewing_angle, S, &hori_dist);
	real_dist = hori_dist * cos(plane_angle / (double)180 * M_PI);
	offset = CUBE_SIZE - 1 - ((int)floor(hori_p.x) % CUBE_SIZE);
	cast_slice(data, real_dist, col, offset);
}

void	e_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	t_point	vert_p;
	double	vert_dist;
	double	real_dist;
	int		offset;

	vert_p = find_vertical_wall(data, viewing_angle, E, &vert_dist);
	real_dist = vert_dist * cos(plane_angle / (double)180 * M_PI);
	offset = (int)floor(vert_p.y) % CUBE_SIZE;
	cast_slice(data, real_dist, col, offset);
}

void	w_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	t_point	vert_p;
	double	vert_dist;
	double	real_dist;
	int		offset;

	vert_p = find_vertical_wall(data, viewing_angle, W, &vert_dist);
	real_dist = vert_dist * cos(plane_angle / (double)180 * M_PI);
	offset = CUBE_SIZE - 1 - ((int)floor(vert_p.y) % CUBE_SIZE);
	cast_slice(data, real_dist, col, offset);
} 

void	cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	if (viewing_angle == 0)
		e_cast_ray(data, plane_angle, viewing_angle, col);
	else if (viewing_angle == 90)
		n_cast_ray(data, plane_angle, viewing_angle, col);
	else if (viewing_angle == 180)
		w_cast_ray(data, plane_angle, viewing_angle, col);
	else if (viewing_angle == 270)
		s_cast_ray(data, plane_angle, viewing_angle, col);
	else if (viewing_angle > 0 && viewing_angle < 90)
		ne_cast_ray(data, plane_angle, viewing_angle, col);
	else if (viewing_angle > 90 && viewing_angle < 180)
		nw_cast_ray(data, plane_angle, viewing_angle, col);
	else if (viewing_angle > 180 && viewing_angle < 270)
		sw_cast_ray(data, plane_angle, viewing_angle, col);
	else if (viewing_angle > 270 && viewing_angle < 360)
		se_cast_ray(data, plane_angle, viewing_angle, col);
}

void	ray_caster(t_data *data)
{
	double	col;
	double	min_angle;
	double	plane_angle;
	double	viewing_angle;

	min_angle = (double)FOV/(double)WIDTH;
	// printf("min_angle: %f\n", min_angle);
	col = 0;
	while (col < WIDTH)
	{
		plane_angle = fabs(min_angle * (col - WIDTH / 2)); // fabs(-30 + min_angle * col);
		viewing_angle = data->player->angle + FOV / 2 - min_angle * col; // data->player->angle + 30 - min_angle * col;
		if (viewing_angle < 0)
			viewing_angle += 360;
		if (viewing_angle >= 360)
			viewing_angle -= 360;
		// printf("viewing_angle: %f\n", viewing_angle);
		cast_ray(data, plane_angle, viewing_angle, col);
		col++;
		//usleep(20000);
	}
}
