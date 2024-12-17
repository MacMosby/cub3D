/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:33:46 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/16 17:26:36 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(t_data *data)
{
	free_everything(data);
	exit(0);
	return (0);
}

/* int	key_handler(int key, void *param)
{
	t_data	*data;

	data = param;
	if (key == XK_Escape)
	{
		free_everything(data);
		exit(1);
	}
	else if (key == XK_Left)
		turn_left(data);
	else if (key == XK_Right)
		turn_right(data);
	else if (key == XK_w || key == XK_W)
		move_forward(data);
	else if (key == XK_a || key == XK_A)
		move_left(data, 0, 0);
	else if (key == XK_s || key == XK_S)
		move_backward(data);
	else if (key == XK_d || key == XK_D)
		move_right(data, 0, 0);
	return (0);
} */

int	key_down(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		free_everything(data);
		exit(1);
	}
	else if (key == XK_Left)
		turn_left(data);
	else if (key == XK_Right)
		turn_right(data);
	else if (key == XK_w || key == XK_W)
		move_forward(data);
	else if (key == XK_a || key == XK_A)
		move_left(data, 0, 0);
	else if (key == XK_s || key == XK_S)
		move_backward(data);
	else if (key == XK_d || key == XK_D)
		move_right(data, 0, 0);
	return (0);
}

int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free(data->player->position);
		free(data->player);
		exit(EXIT_FAILURE);
	}
	set_textures(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	data->imag.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->imag.pixels_ptr = mlx_get_data_addr(data->imag.img_ptr,
			&data->imag.bpp, &data->imag.line_len, &data->imag.endian);
	render(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_down, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, close_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
