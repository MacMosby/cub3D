/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:03:02 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/11 16:37:38 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cast_ray(t_data *data, double plane_angle, double v_angle, int col)
{
	if (v_angle == 0)
		e_cast_ray(data, plane_angle, v_angle, col);
	else if (v_angle == 90)
		n_cast_ray(data, plane_angle, v_angle, col);
	else if (v_angle == 180)
		w_cast_ray(data, plane_angle, v_angle, col);
	else if (v_angle == 270)
		s_cast_ray(data, plane_angle, v_angle, col);
	else if (v_angle > 0 && v_angle < 90)
		ne_cast_ray(data, plane_angle, v_angle, col);
	else if (v_angle > 90 && v_angle < 180)
		nw_cast_ray(data, plane_angle, v_angle, col);
	else if (v_angle > 180 && v_angle < 270)
		sw_cast_ray(data, plane_angle, v_angle, col);
	else if (v_angle > 270 && v_angle < 360)
		se_cast_ray(data, plane_angle, v_angle, col);
}

void	ray_caster(t_data *data)
{
	double	col;
	double	min_angle;
	double	plane_angle;
	double	viewing_angle;

	min_angle = (double)FOV / (double)WIDTH;
	col = 0;
	while (col < WIDTH)
	{
		plane_angle = fabs(min_angle * (col - WIDTH / 2));
		viewing_angle = data->player->angle + FOV / 2 - min_angle * col;
		if (viewing_angle < 0)
			viewing_angle += 360;
		if (viewing_angle >= 360)
			viewing_angle -= 360;
		cast_ray(data, plane_angle, viewing_angle, col);
		col++;
	}
}
