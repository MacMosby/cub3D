/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:24:58 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/06 12:57:44 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_everything(char *input)
{
	t_data	data;
	
	parse_input(input, &data);
	if (!init_mlx(&data))
		return (1);
	if (!init_hooks(&data))
		return (1);
	if (!init_render(&data))
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