/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:29:40 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/12 13:29:41 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_point	get_grid_position(t_point point)
{
	t_point	cube;

	cube.x = floor(point.x / CUBE_SIZE);
	cube.y = floor(point.y / CUBE_SIZE);
	return (cube);
}
