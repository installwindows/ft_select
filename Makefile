# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 21:10:31 by varnaud           #+#    #+#              #
#    Updated: 2017/04/28 21:49:50 by varnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_select
SRC=ft_select.c
OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g -Ilibft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -Llibft -lft -ltermcap

$(OBJ): ft_select.h

libft: libft/libft.h
	make -C libft
