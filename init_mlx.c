/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:33:46 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/26 12:34:44 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int	close_window(t_data *data) // function has to be type int
{
	(void)data;
	// need to clean - code below is from so long, not for cub3d yet
	/* free_textures(data);
	free_map(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr); */
	printf("Exit with clicking X\n");
	cleanup(data);
	exit(0);
	return (0);
}

int	key_handler(int key, void *param)
{
	t_data *data = param;

	if (key == XK_Escape)
	{
		printf("Exit with Escape key\n");
		cleanup(data);
		exit(1);
	}
	else if (key == XK_Left)
		turn_left(data);
	else if (key == XK_Right)
		turn_right(data);
	else if (key == XK_w || key == XK_W)
		move_forward(data);
	else if (key == XK_a || key == XK_A)
		move_left(data);
	else if (key == XK_s || key == XK_S)
		move_backward(data);
	else if (key == XK_d || key == XK_D)
		move_right(data);
	return (0);
}

int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGTH, "cub3D");
	ray_caster(data);
	mlx_key_hook(data->win_ptr, key_handler, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, close_window, &data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
