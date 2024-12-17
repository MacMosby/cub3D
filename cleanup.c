/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:34:21 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/16 17:23:27 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	free_everything(t_data *data)
{
	if (data->map)
		free_array(data->map);
	free(data->player->position);
	free(data->player);
	free(data->we);
	free(data->no);
	free(data->so);
	free(data->ea);
	if (data->mlx_ptr)
	{
		if (data->imag.img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->imag.img_ptr);
		if (data->ea_img.img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->ea_img.img_ptr);
		if (data->no_img.img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->no_img.img_ptr);
		if (data->we_img.img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->we_img.img_ptr);
		if (data->so_img.img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->so_img.img_ptr);
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
