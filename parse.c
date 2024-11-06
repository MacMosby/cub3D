/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:54:01 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/06 13:47:44 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	store_and_check_path(char *path, t_data *data)
{
	data->all_info++;
}

void	parse_firstpart(int fd, char *input, t_data *data)
{
	char	*line;

	while (data->all_info = 5) // init this to zero
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (ft_strncmp(line, "\n", 1)) // if it is not an empty line
		{
			// add sth here to skip over spaces and maybe trim them
			if (!ft_strncmp(line, "NO", 2))
				store_and_check_path(ft_substr(line, 3, (ft_strlen(line) - 3)));
			else if (!ft_strncmp(line, "SO", 2))
				store_and_check_path();
			else if (!ft_strncmp(line, "WE", 2))
				store_and_check_path();
			else if (!ft_strncmp(line, "EA", 2))
				store_and_check_path();
			else if (!ft_strncmp(line, "F", 1))
				store_and_check_floor();
			else
			{
				printf("Error. Could not find expected object information in file\n");
				close(fd);
				exit(EXIT_FAILURE);
			}
		}
	}
	// until here: empty lines ok, spaces ok
}

void	parse_input(char *inputfile, t_data *data)
{
	int	fd;
	
	open(inputfile, O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file. Please check your input.\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	parse_firstpart(fd, inputfile, data);
	check_map(fd, inputfile, data);
	close(fd);
}

int		check_ext(char *mapfile)
{
	int	i;

	i = 0;
	while(mapfile[i] != 0)
		i++;
	if (mapfile[--i] != 'b')
		return (1);
	if (mapfile[--i] != 'u')
		return (1);
	if (mapfile[--i] != 'c')
		return (1);
	if (mapfile[--i] != '.')
		return (1);
	return (0);
}