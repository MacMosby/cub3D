/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:27:27 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/03 16:06:29 by lde-taey         ###   ########.fr       */
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
# include "libft/libft.h"

# define CUBE_SIZE 64
# define MAP_CELL 10
# define FOV 60
# define WIDTH 800
# define HEIGTH 600
# define PLANE_DIST 627
# define MOVE_SPEED 10
# define TURN_SPEED 10
# define NE 1
# define NW 2
# define SW 3
# define SE 4
# define N 5
# define W 6
# define S 7
# define E 8

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
	int		r;
	int		g;
	int		b;
	int		full;
	long		hexa;
}	t_color; // has to look like OxFF0000

typedef struct s_imag
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_imag;

typedef struct s_data
{
	char	**map;
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
	t_imag	imag;
	void	*mlx_ptr_map;
	void	*win_ptr_map;
	//double	plane_dist;
	t_player	*player;
} 	t_data;

// calculate_distance.c
// double	calculate_distance(t_point *p1, t_point *p2, double angle);
double	calculate_distance(t_data *data, t_point *p2, double angle);
// double	calculate_vert_distance(t_point *p1, t_point *p2, double angle);

// cleanup.c
void	cleanup(t_data *data);

// init_mlx.c
int		init_mlx(t_data *data);

// parsing
int		check_ext(char *mapfile);

// player_movement.c
void	move_backward(t_data *data);
void	move_forward(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	turn_left(t_data *data);
void	turn_right(t_data *data);

// ray_caster.c
void	ray_caster(t_data *data);
double	find_horizontal_wall(t_data *data, double viewing_angle, int direction);
double	find_vertical_wall(t_data *data, double viewing_angle, int direction);
double	get_correct_distance(double hori_dist, double vert_dist, double angle);
void	cast_slice(t_data *data, double wall_distance, int col);

// setup
void	init_struct(t_data *data);
int		init_everything(char *input, t_data *data);
int		close_window(t_data *data);

// parsing
int		check_ext(char *mapfile);
void	parse_input(char *inputfile, t_data *data);
char	*parse_firstpart(int fd, t_data *data);
void 	parse_map(int fd, char *inputfile, t_data *data, char **oldline);
void	store_path_no(char *path, t_data *data);
void	store_path_so(char *path, t_data *data);
void	store_path_we(char *path, t_data *data);
void	store_path_ea(char *path, t_data *data);
void	store_and_check_color(char *info, t_color *place);
// void	store_and_check_color_c(char *info, t_data *data);
// void	store_and_check_color_f(char *info, t_data *data);
void 	flood_fill_wall_check(t_data *data);
void 	flood_fill_space_check(t_data *data);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
void	player_check(t_data *data, int fd);
void 	space_check(t_data *data);

// minimap
void	draw_minimap(t_data *data);
void 	init_minimap(t_data *data);
void	draw_player(t_data *data);

// render
void 	render(t_data *data);
void 	my_pixel_put(int x, int y, t_imag *imag, int color);

//testing
void	print_map(t_data *data);
void 	print_struct(t_data *data);


// errors
void	color_error(char **colors);
void	malloc_error(void);
void	map_error(int fd);

// cleanup
void	free_array(char **array);
void	free_everything(t_data *data);


t_point	get_grid_position(t_point point);

#endif
