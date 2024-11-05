/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:24:58 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/05 18:14:55 by lde-taey         ###   ########.fr       */
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
	if (argc == 1 || argc > 2)
	{
		printf("This program needs one (and only one) argument.\n");
		return (1);
	}
	if (check_ext(argv[1]))
	{
		printf("This program only accepts .cub files as an argument\n.");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_args(argc, argv))
		return (1);
	if (init_everything(argv[1]))
		return (1);
	while (1)
	{
		render_update();
	}
	cleanup();
	return (0);
}