/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:54:01 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/17 15:38:30 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_struct(t_data *data)
{
	if (data->ea == NULL)
		return (0);
	if (data->no == NULL)
		return (0);
	if (data->we == NULL)
		return (0);
	if (data->so == NULL)
		return (0);
	if (data->c_ceiling.full == 0)
		return (0);
	if (data->c_floor.full == 0)
		return (0);
	return (1);
}

int	store_information(t_data *data, char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!ft_strncmp(line + i, "NO", 2))
		store_path_no(line + i + 2, data);
	else if (!ft_strncmp(line + i, "SO", 2))
		store_path_so(line + i + 2, data);
	else if (!ft_strncmp(line + i, "WE", 2))
		store_path_we(line + i + 2, data);
	else if (!ft_strncmp(line + i, "EA", 2))
		store_path_ea(line + i + 2, data);
	else if (!ft_strncmp(line + i, "F", 1))
		handle_color_f(line + i + 1, data, line, fd);
	else if (!ft_strncmp(line + i, "C", 1))
		handle_color_c(line + i + 1, data, line, fd);
	else
		return (0);
	return (1);
}

char	*skip_newlines(char *line, int fd)
{
	free(line);
	line = get_next_line(fd);
	while (!ft_strncmp(line, "\n", 1))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

char	*parse_firstpart(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	if (!line || line[0] == '\0')
		information_error(fd, line, data);
	while (check_struct(data) == 0)
	{
		if (ft_strncmp(line, "\n", 1))
		{
			if (!store_information(data, line, fd))
			{
				if (check_struct(data) == 1)
					break ;
				information_error(fd, line, data);
			}
		}
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	line = skip_newlines(line, fd);
	return (line);
}
