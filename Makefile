# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 21:10:31 by varnaud           #+#    #+#              #
#    Updated: 2020/07/14 21:52:41 by varnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_select
SRC=main.c init.c printer.c utils.c ft_select.c signal.c list.c display.c debug.c move.c cap.c control.c page.c resize.c case.c keys.c
OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g -Ilibft
LIBFLAGS=-Llibft -lft -ltermcap

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFLAGS)

$(OBJ): ft_select.h

clean:
	make -C libft clean
	-@rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	-@rm -rf $(NAME)

re: fclean all
