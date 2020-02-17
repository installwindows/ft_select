/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 21:29:34 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/17 17:51:39 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>
# include "libft.h"
# define T_KEY_UP tgetstr("ku", NULL)
# define T_KEY_DOWN tgetstr("kd", NULL)
# define T_KEY_LEFT tgetstr("kl", NULL)
# define T_KEY_RIGHT tgetstr("kr", NULL)
# define T_T_KEY_UP "\e[A"
# define T_T_KEY_DOWN "\e[B"
# define T_T_KEY_RIGHT "\e[C"
# define T_T_KEY_LEFT "\e[D"
# define KEY_UP (1 << 0)
# define KEY_DOWN (1 << 1)
# define KEY_LEFT (1 << 2)
# define KEY_RIGHT (1 << 3)
# define FTS_MARGIN 2

int					g_signals[32];

typedef struct		s_word
{
	int				deleted;
	int				selected;
	int				current;
	int				len;
	char			*value;
	struct s_word	*next;
}					t_word;

typedef struct		s_cur
{
	int				r;
	int				c;
}					t_cur;

typedef struct		s_term
{
	int				width;
	int				height;
	struct termios	oldtio;
	struct termios	newtio;
	char			*mw[16];
}					t_term;

typedef struct		s_display
{
	int				wc_max;
	int				wr_max;
	int				wc;
	int				wr;
	int				nbp;
	int				p;
	t_cur			cur;
}					t_display;

typedef struct		s_case
{
	t_word			*word;
	int				x;
	int				y;
	int				current;
}					t_case;

typedef struct		s_book
{
	t_word			*words;
	int				rows;
	int				cols;
	int				pages;
}					t_book;

typedef struct		s_page
{
	t_case			**cases;
	int				page_no;
	int				rows;
	int				cols;
	int				max_words;
	int				start;
}					t_page;

typedef struct		s_ft_select
{
	t_term			term;
	t_word			**words;
	t_word			*words_list;
	t_cur			cur;
	t_display		display;
	t_word			*current_word;
	t_book			*book;
	int				nbw;
	int				lgw;
}					t_ft_select; 

// list.c
t_word	*create_words_list(int, char **);
void	free_words(t_word *);
t_word	*add_word(char *);
t_word	*delete_word(t_word *, t_word *);
// init.c
void	initialize_terminal(t_ft_select *);
int		init_termcap(t_ft_select *);
void	reset_terminal(t_ft_select *);
// signal.c
void	init_signals(void);
void	check_signals(t_ft_select *);
// utils.c
int		ft_putcap(int);
// ft_select.c
void	ft_select(t_ft_select *);
int		update_display(t_ft_select *);
// printer.c
void	dummy_print_words_list(t_word *words);
void	dummy_print_words(t_word **);
void	print_words(t_ft_select *);
void	basic_printer(t_ft_select *, int, int, int);
// move.c
void	basic_move(int, t_ft_select *);
// main.c
void	clean_exit(t_ft_select *);

#endif
