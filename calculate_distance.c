/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:02:48 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/12 17:14:39 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* calculates and returns the distance between two points */
double	calculate_distance(t_data *data, t_point *p2, double angle)
{
    double dx;
    double dy;
    double distance;
    double relativeAngle;

    dx = p2->x - data->player->position->x;
    dy = p2->y - data->player->position->y;
    distance = sqrt(dx*dx + dy*dy);
    relativeAngle = fabs(angle - data->player->angle);
    if (relativeAngle > 180.0)
        relativeAngle = 360.0 - relativeAngle;
    return (distance);
}
