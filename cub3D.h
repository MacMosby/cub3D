/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:27:27 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/05 18:36:33 by lde-taey         ###   ########.fr       */
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

# define CUBE_SIZE 64
# define FOV 60
# define WIDTH 320
# define HEIGTH 200
# define PLANE_DIST 277
# define MOVE_SPEED 10
# define TURN_SPEED 1

typedef struct s_point t_point;

typedef struct s_player
{
	t_point	position;
	double	angle;
}	t_player;

typedef struct s_point
{
	double x;
	double y;
}	t_point;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
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
	//double	plane_dist;
	t_player	player;
} 	t_data;

// parsing
int		check_ext(char *mapfile);

#endif
