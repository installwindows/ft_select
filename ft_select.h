/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 21:29:34 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/10 19:16:37 by varnaud          ###   ########.fr       */
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

typedef struct		s_word
{
	int				deleted;
	int				selected;
	int				len;
	char			*value;
}					t_word;

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

typedef struct		s_ft_select
{
	t_term			term;
	t_word			**words;
	int				longest_word;
}					t_ft_select;

#endif
