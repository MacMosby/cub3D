/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:27:27 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/07 14:24:18 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"

# define GRID_SIZE 64
# define FOV 60
# define WIDTH 320
# define HEIGTH 200

typedef struct s_point
{
	double x;
	double y;
}	t_point;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	full;
}	t_color;

typedef struct s_data
{
	char	**map;
	char	*we; // path to west texture
	char	*no; // path to north texture
	char 	*so; // path to south texture
	char	*ea; // path to east texture
	t_color	c_floor; // floor color
	t_color	c_ceiling;
	double	plane_dist;
} 	t_data;

// setup
void	init_struct(t_data *data);

// parsing
int		check_ext(char *mapfile);
void	parse_firstpart(int fd, char *input, t_data *data);
void	parse_map(char *mapfile);
void	store_path_no(char *path, t_data *data);
void	store_path_so(char *path, t_data *data);
void	store_path_we(char *path, t_data *data);
void	store_path_ea(char *path, t_data *data);
void	store_and_check_color_f(char *info, t_data *data);

// errors
void	color_error(char **colors);
void	malloc_error(void);

// cleanup
void	free_array(char **array);



#endif
