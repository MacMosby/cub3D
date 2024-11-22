/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:02:48 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/22 15:53:25 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* calculates and returns the distance between two points */
double	calculate_distance(t_point *p1, t_point *p2, double angle)
{
	return (fabs(p1->x - p2->x) / cos(angle / (double)180 * M_PI));
}

// double	calculate_vert_distance(t_point *p1, t_point *p2, double angle)
// {
// 	return (fabs(p1->y - p2->y) / cos(angle / (double)180 * M_PI));
// }