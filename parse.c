/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:54:01 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/05 18:15:13 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_map(char *mapfile)
{
	
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