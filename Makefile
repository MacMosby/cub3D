# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 15:17:42 by lde-taey          #+#    #+#              #
#    Updated: 2024/11/22 14:13:42 by lde-taey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Werror -Wall -Wextra -g

CC = cc

MLX = minilibx-linux/libmlx.a #-Lminilibx-linux -lmlx_Linux

SRCS = main.c \
	calculate_distance.c \
	cleanup.c \
	init.c \
	init_mlx.c \
	player_movement.c \
	ray_caster.c \
	casting.c \
	find_horizontal_wall.c \
	find_vertical_wall.c \
	errors.c \
	parse_checks.c \
	parse_colors.c \
	parse_floodfill.c \
	parse_input.c \
	parse_map.c \
	parse_textures.c \
	parse_utils.c \
	parse_store_paths.c \
	testing.c #remove

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
