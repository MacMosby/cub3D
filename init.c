/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:17:25 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/07 13:23:43 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_struct(t_data *data)
{
	data->ea = "hello";
	data->no = "hello";
	data->so = "hello";
	data->we = "hello";
	data->c_ceiling.r = 0;
	data->c_ceiling.g = 0;
	data->c_ceiling.b = 0;
	data->c_ceiling.full = 0;
	data->c_floor.r = 0;
	data->c_floor.g = 0;
	data->c_floor.b = 0;
	data->c_floor.full = 0;
}

// int	init_everything(char *input)
// {
// 	t_data	data;
	
// 	init_struct(&data);
// 	parse_input(input, &data);
// 	if (!init_mlx(&data))
// 		return (1);
// 	if (!init_hooks(&data))
// 		return (1);
// 	if (!init_render(&data))
// 		return (1);
// 	return (0);
// }