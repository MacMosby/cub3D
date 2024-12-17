# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 15:17:42 by lde-taey          #+#    #+#              #
#    Updated: 2024/12/17 16:24:10 by lde-taey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Werror -Wall -Wextra #-fsanitize=address

CC = cc

MLX = minilibx-linux/libmlx.a #-Lminilibx-linux -lmlx_Linux

SRCS = main.c \
	calculate_distance.c \
	cleanup.c \
	init.c \
	init_mlx.c \
	player_movement.c \
	ray_caster.c \
	ray_caster_axis.c \
	ray_caster_zones.c \
	casting.c \
	find_horizontal_wall.c \
	find_vertical_wall.c \
	errors.c \
	minimap.c \
	minimap_tools.c \
	parse_checks.c \
	parse_checks_tools.c \
	parse_colors.c \
	parse_floodfill.c \
	parse_floodfill_tools.c \
	parse_input.c \
	parse_map.c \
	parse_map_tools.c \
	parse_textures.c \
	parse_utils.c \
	parse_store_paths.c \
	render.c \
	player_turns.c \
	get_grid_position.c \
	set_textures.c 

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make -C minilibx-linux
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME) $(MLX) -lX11 -lXext -lm

all : $(NAME)

.PHONY : clean fclean re

clean :
	make clean -C ./libft
	rm -f $(OBJS)

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)

re : fclean all
