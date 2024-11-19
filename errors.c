/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:48:56 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/18 16:37:02 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void malloc_error(void)
{
	printf("Error. Malloc failed");
	// cleanup;
	exit(EXIT_FAILURE);
}

void	color_error(char **colors)
{
	printf("Error. The color input does not have the right format.\n");
	printf("Only 3 integers between 0 and 255 are allowed.\n");
	free_array(colors);
	exit(EXIT_FAILURE);
}

void	map_error(int fd)
{
	printf("Error. Could not find expected map information in file\n");
	close(fd);
	exit(EXIT_FAILURE);
}