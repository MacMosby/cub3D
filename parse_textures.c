/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:54:01 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/07 14:24:39 by lde-taey         ###   ########.fr       */
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
	if (data->c_ceiling.full == 0) // do differently?
		return (0);
	if (data->c_floor.full == 0)
		return (0);
	return (1);
}

void	parse_firstpart(int fd, char *input, t_data *data)
{
	char	*line;
	int 	i;

	line = get_next_line(fd);
	if (!line || line[0] == '\0')
	{
		printf("Error. Could not find expected object information in file\n");
		close(fd);
		exit(EXIT_FAILURE);
	}	
	while (check_struct(data) == 0)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (ft_strncmp(line, "\n", 1)) // if line is not an empty line
		{
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
				store_and_check_color_f(line + i + 1, data);
			else if (!ft_strncmp(line + i, "C", 1))
				store_and_check_color_c(line + i + 1, data);
			else
			{
				printf("Error. Could not find expected object information in file\n");
				free(line);
				close(fd);
				exit(EXIT_FAILURE);
			}
		}
		free(line);
	}
}

