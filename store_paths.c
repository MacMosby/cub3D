/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:31:12 by lde-taey          #+#    #+#             */
/*   Updated: 2024/11/07 14:23:38 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	store_path_no(char *path, t_data *data)
{
	int i;
	
	while (*path == ' ')
		path++;
	i = 0;
	while (path[i] != '\0')
		i++;
	i--;
	while(path[i] == ' ')
		i--;
	data->no = ft_substr(path, 0, i + 1);
}

void	store_path_so(char *path, t_data *data)
{
	int i;
	
	while (*path == ' ')
		path++;
	i = 0;
	while (path[i] != '\0')
		i++;
	i--;
	while(path[i] == ' ')
		i--;
	data->so = ft_substr(path, 0, i + 1);
}

void	store_path_ea(char *path, t_data *data)
{
	int i;
	
	while (*path == ' ')
		path++;
	i = 0;
	while (path[i] != '\0')
		i++;
	i--;
	while(path[i] == ' ')
		i--;
	data->ea = ft_substr(path, 0, i + 1);
}

void	store_path_we(char *path, t_data *data)
{
	int i;
	
	while (*path == ' ')
		path++;
	i = 0;
	while (path[i] != '\0')
		i++;
	i--;
	while(path[i] == ' ')
		i--;
	data->we = ft_substr(path, 0, i + 1);
}
