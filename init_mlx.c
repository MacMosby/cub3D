/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:33:46 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/12 10:53:41 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int	close_window(t_data *data) // function has to be type int
{
	// need to clean - code below is from so long, not for cub3d yet
	/* free_textures(data);
	free_map(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr); */
	printf("Exit with clicking X\n");
	cleanup(data);
	exit(0); // ugly but what can we do here instead??
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

int	key_down(int key, t_data *data)
{
	printf("num of cols: %d\n", data->cols);
	if (key == XK_w || key == XK_W)
		printf("pressing W\n");
	return (0);
}

void	get_textures(t_data *data)
{
	int size = CUBE_SIZE;

	data->ea_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/star_wars/star_wars_wall_east.xpm", &size, &size);
	data->ea_img.pixels_ptr = mlx_get_data_addr(data->ea_img.img_ptr, &data->ea_img.bpp, &data->ea_img.line_len, &data->ea_img.endian);
	data->no_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/star_wars/star_wars_wall_north.xpm", &size, &size);
	data->no_img.pixels_ptr = mlx_get_data_addr(data->no_img.img_ptr, &data->no_img.bpp, &data->no_img.line_len, &data->no_img.endian);
	data->we_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/star_wars/star_wars_wall_west.xpm", &size, &size);
	data->we_img.pixels_ptr = mlx_get_data_addr(data->we_img.img_ptr, &data->we_img.bpp, &data->we_img.line_len, &data->we_img.endian);
	data->so_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/star_wars/star_wars_wall_south.xpm", &size, &size);
	data->so_img.pixels_ptr = mlx_get_data_addr(data->so_img.img_ptr, &data->so_img.bpp, &data->so_img.line_len, &data->so_img.endian);
}

int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	data->imag.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->imag.pixels_ptr = mlx_get_data_addr(data->imag.img_ptr, &data->imag.bpp, &data->imag.line_len, &data->imag.endian);
	get_textures(data);
	render(data);
	mlx_key_hook(data->win_ptr, key_handler, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_down, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, close_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
