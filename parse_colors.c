/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:20:17 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/12 15:07:51 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_hexa(t_color *place)
{
	return ((place->r << 16) | (place->g << 8) | place->b);
}

// figure out malloc problem with line #TODO
void	color_check_loop(char **colors, t_data *data, char *line)
{
	int		i;
	int		j;
	int		val;

	i = 0;
	val = 0;
	while (i < 3)
	{
		if (colors[i] == NULL)
		{
			free(line);
			line = NULL;
			color_error(colors, data);
		}
		j = 0;
		while (colors[i][j] != '\0')
		{
			if (!ft_isdigit(colors[i][j]) && colors[i][j] != ' ' \
				&& colors[i][j] != '\n')
			{
				free(line);
				color_error(colors, data);
			}
			j++;
		}
		val = ft_atoi(colors[i]);
		if (val < 0 || val > 255)
		{
			free(line);
			color_error(colors, data);
		}
		i++;
	}
}

void	handle_color(char *info, t_color *place, t_data *data, char *line)
{
	char	**colors;

	if (!info || *info == '\0')
		return ; // error handling
	while (*info != '\0' && *info == ' ')
		info++;
	colors = ft_split(info, ',');
	if (!colors || colors[0] == NULL)
	{
		free(line);
		color_error(colors, data);
	}
	color_check_loop(colors, data, line);
	if (colors[3] != NULL)
	{
		free(line);
		color_error(colors, data);
	}
	place->r = ft_atoi(colors[0]);
	place->g = ft_atoi(colors[1]);
	place->b = ft_atoi(colors[2]);
	place->hexa = get_hexa(place);
	free_array(colors);
	place->full = 1;
}
