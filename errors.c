/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:48:56 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/19 15:08:38 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void malloc_error(void)
{
	printf("Error. Malloc failed");
	// cleanup
	exit(EXIT_FAILURE);
}

void	color_error(char **colors)
{
	printf("\nError. The color input does not have the right format.\n");
	printf("Only 3 integers between 0 and 255 are allowed.\n\n");
	free_array(colors);
	exit(EXIT_FAILURE);
}

void	map_error(int fd)
{
	printf("\nError. Could not find all required information in the file\n");
	printf("Please check whether your map has the right format.\n\n");
	close(fd);
	// cleanup;
	exit(EXIT_FAILURE);
}