# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 21:10:31 by varnaud           #+#    #+#              #
#    Updated: 2020/02/18 01:21:23 by varnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_select
SRC=main.c control.c fun.c init.c printer.c utils.c ft_select.c signal.c move.c list.c display.c
OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g -Ilibft -Llibft -lft -ltermcap


.PHONY: all clean fclean re test test_list

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
test:
	$(CC) -o test main.c printer.c init.c signal.c utils.c list.c $(CFLAGS)

test_list:
	$(CC) -o test_list test_list.c list.c $(CFLAGS)

$(OBJ): ft_select.h

libft: libft/libft.h
	make -C libft
