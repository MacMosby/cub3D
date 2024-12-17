/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:48:56 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/17 18:53:00 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	malloc_error(t_data *data)
{
	printf("Error.\nMalloc failed");
	free_everything(data);
	exit(EXIT_FAILURE);
}

void	color_error(char **colors, t_data *data, char *line, int fd)
{
	printf("\nError.\nThe color input does not have the right format.\n");
	printf("Only 3 integers between 0 and 255 are allowed.\n\n");
	free_array(colors);
	free_everything(data);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	exit(EXIT_FAILURE);
}

void	map_error(int fd, t_data *data, char *line)
{
	printf("\nError.\nCould not find all required information in the file\n");
	printf("Please check whether your map has the right format.\n\n");
	free_everything(data);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	exit(EXIT_FAILURE);
}

void	map_error2(int fd, t_data *data)
{
	printf("\nError.\nCould not find all required information in the file\n");
	printf("Please check whether your map has the right format.\n\n");
	close(fd);
	free_everything(data);
	exit(EXIT_FAILURE);
}
