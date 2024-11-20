/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:27:27 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/11/20 16:07:47 by lde-taey         ###   ########.fr       */
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
	int	r;
	int	g;
	int	b;
	int	full;
}	t_color; // has to look like OxFF0000

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
	//double	plane_dist;
	t_player	player;
} 	t_data;

// setup
void	init_struct(t_data *data);
int		init_everything(char *input, t_data *data);

// parsing
int		check_ext(char *mapfile);
void	parse_input(char *inputfile, t_data *data);
char	*parse_firstpart(int fd, t_data *data);
void 	parse_map(int fd, char *inputfile, t_data *data, char **oldline);
void	store_path_no(char *path, t_data *data);
void	store_path_so(char *path, t_data *data);
void	store_path_we(char *path, t_data *data);
void	store_path_ea(char *path, t_data *data);
void	store_and_check_color_c(char *info, t_data *data);
void	store_and_check_color_f(char *info, t_data *data);
void 	flood_fill_wall_check(t_data *data);
void 	flood_fill_space_check(t_data *data);
char	*ft_strcpy(char *dest, char *src);
void	player_check(t_data *data, int fd);
void 	space_check(t_data *data);


// errors
void	color_error(char **colors);
void	malloc_error(void);
void	map_error(int fd);

// cleanup
void	free_array(char **array);
void	free_everything(t_data *data);


#endif
