/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:24:58 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/05 17:55:43 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_everything(char *map)
{
	parse_map(map);
	if (!init_mlx())
		return (1);
	if (!init_hooks())
		return (1);
	if (!init_render())
		return (1);
	return (0);
}

int check_args(int argc, char **argv)
{
	if (argc > 2)
	{
		printf("This program does not accept more than one argument\n.");
		return (1);
	}
	if (check_ext(argv[1]))
	{
		printf("This program only takes .cub files as argument\n.");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_args(argc, argv))
		return (1);
	if (init_everything(argv[1]))
		return (error_message());
	while (1)
	{
		render_update();
	}
	cleanup();
}