/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:19:29 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/17 12:19:31 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_ea_texture(t_data *data, int size)
{
	data->ea_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->ea, &size, &size);
	if (!data->ea_img.img_ptr)
	{
		printf("Error\nInvalid texture path.");
		free_everything(data);
		exit (-1);
	}
	data->ea_img.pixels_ptr = mlx_get_data_addr(data->ea_img.img_ptr,
			&data->ea_img.bpp, &data->ea_img.line_len, &data->ea_img.endian);
}

void	set_no_texture(t_data *data, int size)
{
	data->no_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->no, &size, &size);
	if (!data->no_img.img_ptr)
	{
		printf("Error\nInvalid texture path.");
		free_everything(data);
		exit (-1);
	}
	data->no_img.pixels_ptr = mlx_get_data_addr(data->no_img.img_ptr,
			&data->no_img.bpp, &data->no_img.line_len, &data->no_img.endian);
}

void	set_we_texture(t_data *data, int size)
{
	data->we_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->we, &size, &size);
	if (!data->we_img.img_ptr)
	{
		printf("Error\nInvalid texture path.");
		free_everything(data);
		exit (-1);
	}
	data->we_img.pixels_ptr = mlx_get_data_addr(data->we_img.img_ptr,
			&data->we_img.bpp, &data->we_img.line_len, &data->we_img.endian);
}

void	set_so_texture(t_data *data, int size)
{
	data->so_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->so, &size, &size);
	if (!data->so_img.img_ptr)
	{
		printf("Error\nInvalid texture path.");
		free_everything(data);
		exit (-1);
	}
	data->so_img.pixels_ptr = mlx_get_data_addr(data->so_img.img_ptr,
			&data->so_img.bpp, &data->so_img.line_len, &data->so_img.endian);
}

void	set_textures(t_data *data)
{
	int	size;

	size = CUBE_SIZE;
	set_ea_texture(data, size);
	set_no_texture(data, size);
	set_we_texture(data, size);
	set_so_texture(data, size);
}
