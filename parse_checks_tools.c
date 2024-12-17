/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checks_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:23:35 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/17 15:27:02 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	zero_horizontal_check(t_data *data, int fd, int i, int j)
{
	if ((j - 1) >= 0)
	{
		if (data->map[i][j - 1] == '*')
			map_error2(fd, data);
	}
	if ((j + 1) == '\0')
		map_error2(fd, data);
	else
	{
		if (data->map[i][j + 1] == '*')
			map_error2(fd, data);
	}
}

void	zero_vertical_check(t_data *data, int fd, int i, int j)
{
	if ((i - 1) >= 0)
	{
		if (data->map[i - 1][j] == '*')
			map_error2(fd, data);
	}
	else
		map_error2(fd, data);
	if (data->map[i + 1] == NULL)
		map_error2(fd, data);
	else
	{
		if (data->map[i + 1][j] == '*')
			map_error2(fd, data);
	}
}
