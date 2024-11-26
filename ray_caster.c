/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:03:02 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/26 17:11:32 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ne_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	double	vert_dist;
	double	hori_dist;
	double	real_dist;

	hori_dist = find_horizontal_wall(data, viewing_angle, UP);
	vert_dist = find_vertical_wall(data, viewing_angle, RIGHT);
	if (hori_dist < 0 && vert_dist < 0)
		printf("NORTH EAST - NO WALL FOUND! \n"); 
	real_dist = get_correct_distance(hori_dist, vert_dist, plane_angle);
	cast_slice(data, real_dist, col);
}

void	nw_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	double	vert_dist;
	double	hori_dist;
	double	real_dist;

	hori_dist = find_horizontal_wall(data, viewing_angle, UP);
	vert_dist = find_vertical_wall(data, viewing_angle, LEFT);
	if (hori_dist < 0 && vert_dist < 0)
		printf("NORTH WEST - NO WALL FOUND!\n");
	real_dist = get_correct_distance(hori_dist, vert_dist, plane_angle);
	cast_slice(data, real_dist, col);
}

void	sw_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	double	vert_dist;
	double	hori_dist;
	double	real_dist;

	hori_dist = find_horizontal_wall(data, viewing_angle, DOWN);
	vert_dist = find_vertical_wall(data, viewing_angle, LEFT);
	if (hori_dist < 0 && vert_dist < 0)
		printf("SOUTH WEST - NO WALL FOUND!\n");
	real_dist = get_correct_distance(hori_dist, vert_dist, plane_angle);
	cast_slice(data, real_dist, col);
}

void	se_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	double	vert_dist;
	double	hori_dist;
	double	real_dist;

	hori_dist = find_horizontal_wall(data, viewing_angle, DOWN);
	vert_dist = find_vertical_wall(data, viewing_angle, RIGHT);
	if (hori_dist < 0 && vert_dist < 0)
		printf("SOUTH EAST - NO WALL FOUND!\n");
	real_dist = get_correct_distance(hori_dist, vert_dist, plane_angle);
	cast_slice(data, real_dist, col);
}

void	n_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	double	hori_dist;
	double	real_dist;

	hori_dist = find_horizontal_wall(data, viewing_angle, UP);
	if (hori_dist < 0)
		printf("NORTH no wall found\n");
	real_dist = hori_dist * cos(plane_angle / (double)180 * M_PI);
	cast_slice(data, real_dist, col);
}

void	s_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	double	hori_dist;
	double	real_dist;

	hori_dist = find_horizontal_wall(data, viewing_angle, DOWN);
	if (hori_dist < 0)
		printf("SOUTH no wall found\n");
	real_dist = hori_dist * cos(plane_angle / (double)180 * M_PI);
	cast_slice(data, real_dist, col);
}

void	e_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	double	vert_dist;
	double	real_dist;

	vert_dist = find_vertical_wall(data, viewing_angle, RIGHT);
	if (vert_dist < 0)
		printf("EAST no wall found\n");
	real_dist = vert_dist * cos(plane_angle / (double)180 * M_PI);
	cast_slice(data, real_dist, col);
}

void	w_cast_ray(t_data *data, double plane_angle, double viewing_angle, int col)
{
	double	vert_dist;
	double	real_dist;

	vert_dist = find_vertical_wall(data, viewing_angle, LEFT);
	if (vert_dist < 0)
		printf("EAST no wall found\n");
	real_dist = vert_dist * cos(plane_angle / (double)180 * M_PI);
	cast_slice(data, real_dist, col);
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
		viewing_angle = data->player->angle + FOV/2 - min_angle * col; // data->player->angle + 30 - min_angle * col;
		if (viewing_angle < 0)
			viewing_angle += 360;
		// printf("viewing_angle: %f\n", viewing_angle);
		cast_ray(data, plane_angle, viewing_angle, col);
		col++;
		//usleep(20000);
	}
}
