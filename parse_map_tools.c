/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:22:06 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/17 14:42:37 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cleanup_and_error(int fd, t_data *data, char *line, char *newrow)
{
	free(newrow);
	newrow = NULL;
	map_error(fd, data, line);
}

int	line_error_checks(char *line, int fd, t_data *data, char *newrow)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
	{
		line[i] = '*';
		i++;
	}
	if (line[i] == '\n')
		cleanup_and_error(fd, data, line, newrow);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'N' \
			|| line[i] == 'S' || line[i] == 'W' \
			|| line[i] == 'E' || line[i] == ' '))
			cleanup_and_error(fd, data, line, newrow);
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
	i = line_error_checks(line, fd, data, newrow);
	printf("This is i: %i\n", i);
	len = ft_strlen(line);
	printf("This is len: %i\n", len);
	if (line[i] != '\n')
		len++;
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
