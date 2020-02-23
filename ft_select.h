/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 21:29:34 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/23 01:53:16 by varnaud          ###   ########.fr       */
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
# define KEY_SPACE (1 << 4)
# define KEY_BACKSPACE (1 << 5)
# define KEY_ESCAPE (1 << 6)
# define KEY_DELETE (1 << 7)
# define KEY_RETURN (1 << 8)
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

typedef struct		s_term
{
	int				width;
	int				height;
	struct termios	oldtio;
	struct termios	newtio;
	char			*mw[16];
}					t_term;

typedef struct		s_case
{
	t_word			*word;
	int				x;
	int				y;
	int				active;
}					t_case;

typedef struct		s_page
{
	t_case			**cases;
	int				mid_width;
	int				mid_height;
	int				word_width;
	int				word_height;
	int				page_no;
	int				max_words;
	struct s_page	*next;
}					t_page;

typedef struct		s_book
{
	t_word			*word_list;
	int				word_list_size;
	int				longest_word;
	int				xw_max;
	int				yw_max;
	int				xw;
	int				yw;
	int				nb_page;
	t_page			*pages;
}					t_book;

typedef struct		s_reader
{
	t_page			*page;
	t_word			*word;
	t_case			*box;
	int				bxi;
	int				byi;
}					t_reader;

typedef struct		s_ft_select
{
	t_term			term;
	t_word			*word_list;
	t_book			book;
	t_reader		reader;
}					t_ft_select; 

// list.c
t_word	*create_words_list(int, char **);
void	free_words(t_word *);
t_word	*add_word(char *);
t_word	*delete_word(t_word *, t_word *);
int		get_word_list_size(t_word *);
// init.c
void	initialize_terminal(t_ft_select *);
int		init_termcap(t_ft_select *);
void	reset_terminal(t_ft_select *);
t_word	*get_word_no(t_word *, int);
// signal.c
void	init_signals(void);
void	check_signals(t_ft_select *);
// utils.c
int		ft_putcap(int);
int		get_longest_word(t_word *words);
// ft_select.c
void	ft_select(t_ft_select *);
int		update_display(t_ft_select *);
// printer.c
void	dummy_print_words_list(t_word *words);
// move.c
void	move(int, int, t_page *, t_ft_select *);
// main.c
void	clean_exit(t_ft_select *);
// display.c
void	test_display(t_ft_select *);
// debug.c
void	display_debug_info(t_ft_select *);
// cap.c
void	underline(char *);
// control.c
void	handle_space(t_ft_select *);
void	move_cursor_to(int, int);
void	reverse_video(char *);

#endif
