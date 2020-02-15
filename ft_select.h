/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 21:29:34 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/15 20:05:02 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>
# include "libft.h"
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
	int				len;
	char			*value;
}					t_word;

typedef struct		s_cur
{
	int				x;
	int				y;
}					t_cur;

typedef struct		s_term
{
	int				width;
	int				height;
	t_cur			cur;
	struct termios	oldtio;
	struct termios	newtio;
	char			*mw[16];
}					t_term;

typedef struct		s_ft_select
{
	t_term			term;
	t_word			**words;
	int				nbw;
	int				lgw;
}					t_ft_select; 

void	initialize_terminal(t_ft_select *);
int		init_termcap(t_ft_select *);
void	init_signals(void);
void	check_signals(t_ft_select *);
void	reset_terminal(t_ft_select *);
int		ft_putcap(int);
void	ft_select(t_ft_select *);

void	dummy_print_words(t_word **);
void	print_words(t_ft_select *);
void	basic_printer(t_ft_select *, int, int, int);
int		update_display(t_ft_select *);

void	clean_exit(t_ft_select *);

#endif
