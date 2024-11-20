/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:34:21 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/12 16:34:22 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cleanup(t_data *data)
{
	// free all the allocated stuff
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr); // not sure if this is necessary - needs to be tested
}

void free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while(array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void free_everything(t_data *data)
{
	free_array(data->map);
}
