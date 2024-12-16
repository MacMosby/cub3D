/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:22:06 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/13 15:25:12 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	line_error_checks(char *line, int fd, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
	{
		line[i] = '*';
		i++;
	}
	if (line[i] == '\n')
		map_error(fd, data, line);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'N' \
			|| line[i] == 'S' || line[i] == 'W' \
			|| line[i] == 'E' || line[i] == ' '))
			map_error(fd, data, line);
		i++;
	}
	return (i);
}

char	*handle_line(char *line, t_data *data, int fd)
{
	int		i;
	int		len;
	char	*newrow;

	newrow = (char *)malloc((data->cols + 1) * sizeof(char));
	i = line_error_checks(line, fd, data);
	len = ft_strlen(line);
	ft_strlcpy(newrow, line, len);
	if (len < data->cols + 1)
	{
		while (i < data->cols)
		{
			newrow[i] = '*';
			i++;
		}
		newrow[i] = '\0';
	}
	return (newrow);
}

char	*find_start_map(int fd, char **oldline)
{
	char	*line;

	line = get_next_line(fd);
	while (ft_strcmp(line, *oldline))
	{
		free(line);
		line = get_next_line(fd);
	}
	free(*oldline);
	*oldline = NULL;
	return (line);
}
