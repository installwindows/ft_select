# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 21:10:31 by varnaud           #+#    #+#              #
#    Updated: 2020/02/17 17:19:15 by varnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_select
SRC=main.c control.c fun.c init.c printer.c utils.c ft_select.c signal.c move.c
OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g -Ilibft -Llibft -lft -ltermcap


.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
test:
	$(CC) -o test main.c printer.c init.c signal.c utils.c $(CFLAGS)

$(OBJ): ft_select.h

libft: libft/libft.h
	make -C libft
