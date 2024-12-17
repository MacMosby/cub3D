/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:40:56 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/17 15:28:31 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	store_map(t_data *data, char *inputfile, char **oldline)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(inputfile, O_RDONLY);
	data->map = (char **)ft_calloc((data->rows + 1), sizeof(char *));
	i = 0;
	line = find_start_map(fd, oldline);
	data->map[i] = handle_line(line, data, fd);
	while (i < (data->rows - 1))
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		data->map[++i] = handle_line(line, data, fd);
	}
	data->map[++i] = NULL;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	check_if_end(char *line, int fd)
{
	char	*storage;

	storage = ft_strdup(line);
	while (line != NULL && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
	{
		free(storage);
		return (1);
	}
	else
	{
		free(line);
		line = storage;
		free(storage);
		return (0);
	}
}

void	map_loop(t_data *data, char *line, int fd, char **oldline)
{
	int	len;

	len = 0;
	data->rows++;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			if (check_if_end(line, fd))
				break ;
			else
			{
				free (*oldline); 
				map_error(fd, data, line);
			}
		}
		data->rows++;
		len = ft_strlen(line) - 1;
		if (len > data->cols)
			data->cols = len;
	}
}

void	parse_map(int fd, char *inputfile, t_data *data, char **oldline)
{
	char	*line;

	line = ft_strdup(*oldline);
	if (!line || line[0] == '\0')
	{
		free (*oldline);
		map_error(fd, data, line);
	}
	map_loop(data, line, fd, oldline);
	close(fd);
	store_map(data, inputfile, oldline);
	player_check(data, fd);
	flood_fill_wall_check(data);
	flood_fill_space_check(data);
	space_check(data);
	zero_check(data, fd);
}
