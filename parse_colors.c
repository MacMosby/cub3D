/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:20:17 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/07 16:33:45 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	color_check_loop(char **colors)
{
	int		i;
	int		j;
	int		val;
	
	i = 0;
	val = 0;
	while (i < 3)
	{
		if(colors[i] == NULL)
			color_error(colors);
		j = 0;
		while(colors[i][j] != '\0')
		{
			if(!ft_isdigit(colors[i][j]) && colors[i][j] != ' ')
				color_error(colors);
			j++;
		}
		val = ft_atoi(colors[i]);
		if (val < 0 || val > 255)
			color_error(colors);
		i++;
	}
}

void	store_and_check_color_c(char *info, t_data *data) // add color struct to make it one function
{
	char 	**colors;

	if (!info || *info == '\0')
		return ; // error handling
	while(*info != '\0' && *info == ' ')
		info++;
	colors = ft_split(info, ',');
	if (!colors || colors[0] == NULL)
		color_error(colors);
	color_check_loop(colors);
	if (colors[3] != NULL)
		color_error(colors);
	data->c_ceiling.r = ft_atoi(colors[0]);
	data->c_ceiling.g = ft_atoi(colors[1]);
	data->c_ceiling.b = ft_atoi(colors[2]);
	free_array(colors);
	data->c_ceiling.full = 1;
}

void	store_and_check_color_f(char *info, t_data *data)
{
	char 	**colors;

	if (!info || *info == '\0')
		return ; // error handling
	while(*info != '\0' && *info == ' ')
		info++;
	colors = ft_split(info, ',');
	if (!colors || colors[0] == NULL)
		color_error(colors);
	color_check_loop(colors);
	if (colors[3] != NULL)
		color_error(colors);
	data->c_floor.r = ft_atoi(colors[0]); // check for integer overflow
	data->c_floor.g = ft_atoi(colors[1]);
	data->c_floor.b = ft_atoi(colors[2]);
	free_array(colors);
	data->c_floor.full = 1;
}
