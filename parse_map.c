/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:40:56 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/22 13:48:10 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char *handle_line(char *line, t_data *data, int fd)
{
	int 	i;
	int 	len;
	char	*newrow;

	newrow = (char *)malloc((data->cols + 1) * sizeof(char));
	i = 0;
	while(line[i] != '\0' && line[i] == ' ')
	{
		line[i] = '*';
		i++;
	}
	if (line[i] == '\n')
		map_error(fd);
	while(line[i] != '\0' && line[i] != '\n')
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S' || line[i] == 'W' \
			|| line[i] == 'E' || line[i] == ' '))
			map_error(fd);
		i++;
	}
	len = ft_strlen(line);
	ft_strlcpy(newrow, line, len);
	if (len < data->cols + 1)
	{
		while(i < data->cols)
		{
			newrow[i] = '*';
			i++;
		}
		newrow[i] = '\0';
	}
	return (newrow);
}

void store_map(t_data *data, char *inputfile, char **oldline)
{
	int		fd;
	char	*line;
	int 	i;

	fd = open(inputfile, O_RDONLY);
	data->map = (char**)malloc((data->rows + 1) * sizeof(char *));
	if (!data->map)
		malloc_error();
	i = 0;
	line = get_next_line(fd);
	while(ft_strcmp(line, *oldline))
	{
		free(line);
		line = get_next_line(fd);
	}
	free(*oldline);
	*oldline = NULL;
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
	free(line);
	close(fd);
	// print_map(data);
}

void parse_map(int fd, char *inputfile, t_data *data, char **oldline)
{
	int		len;
	char 	*line;

	// 1. get_dimensions
	line = ft_strdup(*oldline);
	if (!line || line[0] == '\0')
		map_error(fd);
	data->rows++;
	while (line != NULL)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
			map_error(fd);
		data->rows++;
		len = ft_strlen(line) - 1;
		if (len > data->cols)
			data->cols = len;
	}
	close(fd);
	// printf("This is the amount of columns: %i\n", data->cols);
	// printf("This is the amount of rows: %i\n", data->rows);
	// printf("This is the file: %s\n", inputfile);
		
	// 2. store map
	store_map(data, inputfile, oldline);
	
	// 3. checks
	player_check(data, fd);
	flood_fill_wall_check(data);
	flood_fill_space_check(data);
	space_check(data);
}