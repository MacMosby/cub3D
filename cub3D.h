/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:27:27 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/12/16 16:48:26 by lde-taey         ###   ########.fr       */
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
# include "colors.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"

# define CUBE_SIZE 64
# define MM_OFFSET 10
# define MAP_CELL 10
# define MM_WIDTH 220
# define MM_HEIGHT 140
# define FOV 60
# define WIDTH 800
# define HEIGHT 600
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

typedef struct s_point	t_point;

typedef struct s_player
{
	t_point	*position;
	double	angle;
}	t_player;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		full;
	long	hexa;
}	t_color;

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
	char		**map;
	int			rows;
	int			cols;
	char		*we;
	char		*no;
	char		*so;
	char		*ea;
	t_color		c_floor;
	t_color		c_ceiling;
	void		*mlx_ptr;
	void		*win_ptr;
	t_imag		imag;
	t_imag		ea_img;
	t_imag		no_img;
	t_imag		we_img;
	t_imag		so_img;
	int			wall;
	float		mm_xstart;
	float		mm_ystart;
	t_player	*player;
}	t_data;

// calculate_distance.c
double	calculate_distance(t_data *data, t_point *p2);

// init_mlx.c
int		init_mlx(t_data *data);

// parsing
int		check_ext(char *mapfile);

// player_movement.c
void	move_backward(t_data *data);
void	move_forward(t_data *data);
void	move_left(t_data *data, double dx, double dy);
void	move_right(t_data *data, double dx, double dy);
void	turn_left(t_data *data);
void	turn_right(t_data *data);

// ray_caster.c
void	ray_caster(t_data *data);
t_point	find_horizontal_wall(t_data *data, double viewing_angle, \
	int direction, double *dist);
t_point	find_vertical_wall(t_data *data, double viewing_angle, \
	int direction, double *dist);
double	get_correct_distance(double hori_dist, \
	double vert_dist, double angle);
void	cast_slice(t_data *data, double wall_distance, \
	int col, int offset);

// ray_caster_axis.c
void	n_cast_ray(t_data *data, double plane_angle, \
	double viewing_angle, int col);
void	s_cast_ray(t_data *data, double plane_angle, \
	double viewing_angle, int col);
void	e_cast_ray(t_data *data, double plane_angle, \
	double viewing_angle, int col);
void	w_cast_ray(t_data *data, double plane_angle, \
	double viewing_angle, int col);

// ray_caster_zones.c
void	ne_cast_ray(t_data *data, double plane_angle, \
	double viewing_angle, int col);
void	nw_cast_ray(t_data *data, double plane_angle, \
	double viewing_angle, int col);
void	sw_cast_ray(t_data *data, double plane_angle, \
	double viewing_angle, int col);
void	se_cast_ray(t_data *data, double plane_angle, \
	double viewing_angle, int col);

// setup
void	init_struct(t_data *data);
int		init_everything(char *input, t_data *data);
int		close_window(t_data *data);

// parsing
int		check_ext(char *mapfile);
void	parse_input(char *inputfile, t_data *data);
char	*parse_firstpart(int fd, t_data *data);
void	parse_map(int fd, char *inputfile, t_data *data, char **oldline);
char	*find_start_map(int fd, char **oldline);
char	*handle_line(char *line, t_data *data, int fd);
int		line_error_checks(char *line, int fd, t_data *data, char *newrow);
void	store_path_no(char *path, t_data *data);
void	store_path_so(char *path, t_data *data);
void	store_path_we(char *path, t_data *data);
void	store_path_ea(char *path, t_data *data);
void	handle_color_f(char *info, t_data *data, char *line, int fd);
void	handle_color_c(char *info, t_data *data, char *line, int fd);
void	flood_fill_wall_check(t_data *data);
void	flood_fill_space_check(t_data *data);
char	**create_visited_matrix(t_data *data);
void	look_for_player(t_data *data, int *point_x, int *point_y);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
void	player_check(t_data *data, int fd);
void	space_check(t_data *data);

// minimap
void	draw_minimap(t_data *data);
void	init_minimap(t_data *data);
void	draw_player(t_data *data);
void	draw_rays(t_data *data);
float	ft_normalize(float angle);

// render
void	render(t_data *data);
void	my_pixel_put(int x, int y, t_imag *imag, int color);

// errors
void	color_error(char **colors, t_data *data, char *line, int fd);
void	malloc_error(t_data *data);
void	map_error(int fd, t_data *data, char *line);
void	map_error2(int fd, t_data *data);
void	information_error(int fd, char *line);

// cleanup
void	free_array(char **array);
void	free_everything(t_data *data);

t_point	get_grid_position(t_point point);

// set_textures.c
void	set_textures(t_data *data);

#endif
