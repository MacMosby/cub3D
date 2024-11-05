# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 15:17:42 by lde-taey          #+#    #+#              #
#    Updated: 2024/11/05 17:56:34 by lde-taey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Werror -Wall -Wextra -g

CC = gcc

MLX = minilibx-linux/libmlx.a

SRCS = main.c \
	parse.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) -lX11 -lXext -lm

all : $(NAME)

.PHONY : clean fclean re

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all