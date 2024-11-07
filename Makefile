# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 15:17:42 by lde-taey          #+#    #+#              #
#    Updated: 2024/11/06 14:50:41 by lde-taey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Werror -Wall -Wextra -g

CC = gcc

MLX = minilibx-linux/libmlx.a

SRCS = main.c \
	parse_input.c \
	parse_map.c \
	parse_texture.c \
	errors.c \
	ray_caster.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
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