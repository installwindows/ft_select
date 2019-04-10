/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 21:29:34 by varnaud           #+#    #+#             */
/*   Updated: 2019/04/10 16:30:54 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <term.h>
# include "libft.h"
# define KEY_UP (1 << 0)
# define KEY_DOWN (1 << 1)
# define KEY_LEFT (1 << 2)
# define KEY_RIGHT (1 << 3)

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

#endif
