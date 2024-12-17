/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:20:17 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/17 18:36:26 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_hexa(t_color *place)
{
	return ((place->r << 16) | (place->g << 8) | place->b);
}

int	check_color_value(char *color)
{
	int	j;

	j = 0;
	while (color[j] != '\0')
	{
		if (!ft_isdigit(color[j]) && color[j] != ' ' \
			&& color[j] != '\n')
			return (0);
		j++;
	}
	return (1);
}

void	color_check_loop(char **colors, t_data *data, char *line, int fd)
{
	int		i;
	int		val;

	i = 0;
	val = 0;
	while (i < 3)
	{
		if (colors[i] == NULL || (colors[i][0] == '\n' && colors[i][1] == '\0'))
			color_error(colors, data, line, fd);
		if (!check_color_value(colors[i]))
			color_error(colors, data, line, fd);
		val = ft_atoi(colors[i]);
		if (val < 0 || val > 255)
			color_error(colors, data, line, fd);
		i++;
	}
}

void	handle_color_c(char *info, t_data *data, char *line, int fd)
{
	char	**colors;

	if (data->c_ceiling.full == 1)
		information_error(fd, line, data);
	colors = NULL;
	if (!info || *info == '\0')
		color_error(colors, data, line, fd);
	while (*info != '\0' && *info == ' ')
		info++;
	colors = ft_split(info, ',');
	if (!colors || colors[0] == NULL)
		color_error(colors, data, line, fd);
	color_check_loop(colors, data, line, fd);
	if (colors[3] != NULL)
		color_error(colors, data, line, fd);
	data->c_ceiling.r = ft_atoi(colors[0]);
	data->c_ceiling.g = ft_atoi(colors[1]);
	data->c_ceiling.b = ft_atoi(colors[2]);
	data->c_ceiling.hexa = get_hexa(&data->c_ceiling);
	free_array(colors);
	data->c_ceiling.full = 1;
}

void	handle_color_f(char *info, t_data *data, char *line, int fd)
{
	char	**colors;

	if (data->c_floor.full == 1)
		information_error(fd, line, data);
	colors = NULL;
	if (!info || *info == '\0') 
		color_error(colors, data, line, fd);
	while (*info != '\0' && *info == ' ')
		info++;
	colors = ft_split(info, ',');
	if (!colors || colors[0] == NULL)
		color_error(colors, data, line, fd);
	color_check_loop(colors, data, line, fd);
	if (colors[3] != NULL)
		color_error(colors, data, line, fd);
	data->c_floor.r = ft_atoi(colors[0]);
	data->c_floor.g = ft_atoi(colors[1]);
	data->c_floor.b = ft_atoi(colors[2]);
	data->c_floor.hexa = get_hexa(&data->c_floor);
	free_array(colors);
	data->c_floor.full = 1;
}
