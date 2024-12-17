/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:52:48 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/17 18:53:19 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	information_error(int fd, char *line, t_data *data)
{
	printf("Error.\nCould not find expected object information in file\n");
	free_everything(data);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	exit(EXIT_FAILURE);
}

void	special_error(int fd, t_data *data, char *line)
{
	printf("\nError.\nFound wrong information in the file\n");
	printf("Please check whether your file has the right format.\n\n");
	free_everything(data);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	exit(EXIT_FAILURE);
}
