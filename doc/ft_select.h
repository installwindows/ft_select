/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 21:29:34 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/08 00:05:13 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <term.h>
# include "libft.h"
# define KEY_UP 1
# define KEY_DOWN 2
# define KEY_LEFT 3
# define KEY_RIGHT 4
# define KEY_ENTER 5
# define KEY_SPACE 6
# define T_KEY_UP tgetstr("ku", NULL)
# define T_KEY_DOWN tgetstr("kd", NULL)
# define T_KEY_LEFT tgetstr("kl", NULL)
# define T_KEY_RIGHT tgetstr("kr", NULL)
# define T_T_KEY_UP "\e[A"
# define T_T_KEY_DOWN "\e[B"
# define T_T_KEY_RIGHT "\e[C"
# define T_T_KEY_LEFT "\e[D"

typedef struct		s_select
{
	char			*arg;
	int				selected;
	struct s_select	*prev;
	struct s_select	*next;
}					t_select;

typedef struct	s_cur
{
	int			x;
	int			y;
}				t_cur;

typedef struct	s_term
{
	int			width;
	int			height;
	t_cur		cur;
}				t_term;

typedef struct	s_args
{
	char		**argv;
	int			argc;
	int			longest;
}				t_args;

typedef struct	s_cursor
{
	int			c;
	int			l;
	int			x;
	int			y;
}				t_cursor;

typedef struct	s_element
{
	char		*value;
	int			len;
	int			selected;
	int			l;
	int			c;
}				t_element;

void			init_termcap(void);
struct termios	initialize_terminal(void);
int				ft_putcap(int c);
int				is(const char *input, int key_code);
void			move(int key_code);


#endif
