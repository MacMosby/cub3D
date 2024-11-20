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
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define CUBE_SIZE 64
# define FOV 60
# define WIDTH 320
# define HEIGTH 200
# define PLANE_DIST 277
# define MOVE_SPEED 10
# define TURN_SPEED 1
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

typedef struct s_point t_point;

typedef struct s_player
{
	t_point	*position;
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
	int		**map;
	int		rows;
	int		cols;
	char	*we; // path to west texture
	char	*no; // path to north texture
	char 	*so; // path to south texture
	char	*ea; // path to east texture
	t_color	c_floor; // floor color
	t_color	c_ceiling;
	void	*mlx_ptr;
	void	*win_ptr;
	//double	plane_dist;
	t_player	*player;
} 	t_data;

// calculate_distance.c
double	calculate_distance(t_point *p1, t_point *p2, double angle);

// cleanup.c
void	cleanup(t_data *data);

// init_mlx.c
int		init_mlx(t_data *data);

// parsing
int		check_ext(char *mapfile);
void	parse_map(char *mapfile);

// player_movement.c
void	move_backward(t_data *data);
void	move_forward(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	turn_left(t_data *data);
void	turn_right(t_data *data);

// ray_caster.c
void	ray_caster(t_data *data);

int	init_everything(t_data *data, char *map);
double	find_horizontal_wall(t_data *data, double viewing_angle, int direction);
double	find_vertical_wall(t_data *data, double viewing_angle, int direction);
double	get_correct_distance(double hori_dist, double vert_dist, double angle);
void	cast_slice(t_data *data, double wall_distance, int col);

#endif
