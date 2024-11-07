/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:10:27 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/06 14:10:59 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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