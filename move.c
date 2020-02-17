/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:47:30 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/16 02:01:00 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_word	*get_word_by_cr(int c, int r, t_ft_select *fts)
{
	int		w;

	w = c * fts->display.wr + r;
	if (w < fts->nbw)
		return (fts->words[w]);
	return (NULL);
}

void	select_word(t_ft_select *fts)
{
	t_word *word;

	word = get_word_by_cr(fts->display.cur.c, fts->display.cur.r, fts);
	word->current = 1;
	fts->current_word = word;
}

void	move_cursor(int x, int y, t_ft_select *fts)
{
	/* int		c; */
	/* int		r; */

	/* c = y; */
	/* r = x; */
	fts->current_word->selected = 0;
	x = x + fts->display.cur.r;
	y = y + fts->display.cur.c;
	if (x > fts->display.wr)
		x = 0;
	else if (x < 0)
		x = fts->display.wr;
	if (y > fts->display.wc)
		y = 0;
	else if (y < 0)
		y = fts->display.wc;
	fts->display.cur.r = x;
	fts->display.cur.c = y;
	select_word(fts);
}

void	basic_move(int key_code, t_ft_select *fts)
{
	if (key_code == KEY_UP)
	{
		ft_printf("UP");
		move_cursor(0, -1, fts);
	}
	else if (key_code == KEY_DOWN)
	{
		move_cursor(0, 1, fts);
	}
	else if (key_code == KEY_LEFT)
	{
		move_cursor(-1, 0, fts);
	}
	else if (key_code == KEY_RIGHT)
	{
		move_cursor(1, 0, fts);
	}
}
