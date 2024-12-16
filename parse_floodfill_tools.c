/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floodfill_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:12:42 by lde-taey          #+#    #+#             */
/*   Updated: 2024/12/16 15:27:01 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**create_visited_matrix(t_data *data)
{
	char	**visited;
	int		i;
	int		j;

	visited = (char **)malloc((data->rows + 1) * sizeof(char *));
	i = 0;
	while (i < data->rows)
	{
		visited[i] = (char *)malloc((data->cols + 1) * sizeof(char));
		j = 0;
		while (j < data->cols)
		{
			visited[i][j] = 0;
			j++;
		}
		visited[i][j] = '\0';
		i++;
	}
	visited[i] = NULL;
	return (visited);
}

void	look_for_player(t_data *data, int *point_x, int *point_y)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || \
				data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				*point_x = i;
				*point_y = j;
				break ;
			}
			j++;
		}
		if (*point_x != -1)
			break ;
		i++;
	}
}
