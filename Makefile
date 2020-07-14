# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 21:10:31 by varnaud           #+#    #+#              #
#    Updated: 2020/07/14 12:52:45 by varnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_select
SRC=main.c init.c printer.c utils.c ft_select.c signal.c list.c display.c debug.c move.c cap.c control.c page.c resize.c case.c
OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g -Ilibft
LIBFLAGS=-Llibft -lft -ltermcap

.PHONY: all clean fclean re test test_list test_key

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFLAGS)
test:
	$(CC) -o test test_highlight.c init.c utils.c $(CFLAGS)

test_list:
	$(CC) -o test_list test_list.c list.c $(CFLAGS)

test_key:
	$(CC) -o test_key test_key.c init.c utils.c cap.c $(CFLAGS) $(LIBFLAGS)

$(OBJ): ft_select.h

libft: libft/libft.h
	make -C libft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
