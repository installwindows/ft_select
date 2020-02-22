/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:11:08 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/22 00:19:14 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		move_cursor_to(int x, int y)
{
	tputs(tgoto(tgetstr("cm", NULL), x, y), 0, ft_putcap);
}

void		change_highlighted(t_case *new, t_ft_select *fts)
{
	move_cursor_to(fts->reader.box->x, fts->reader.box->y);
	ft_printf("%s", fts->reader.word->value);
	move_cursor_to(new->x, new->y);
	fts->reader.box = new;
	fts->reader.word = new->word;
	tputs(tgetstr("so", NULL), 0, ft_putcap);
	ft_printf("%s", fts->reader.word->value);
	tputs(tgetstr("se", NULL), 0, ft_putcap);
}

static void	try_move(int x, int y, t_page *page, t_ft_select *fts)
{
	x += fts->reader.bxi;
	y += fts->reader.byi;
	// absolute checks
	if (x > fts->book.xw)
		x = 0;
	else if (x < 0)
		x = fts->book.xw;
	if (y > fts->book.yw)
		y = 0;
	else if (y < 0)
		y = fts->book.yw;
	// cases checks
	// ...
	fts->reader.bxi = x;
	fts->reader.byi = y;
	change_highlighted(&page->cases[x][y], fts);
}

void	control(int key_code, t_page *page, t_ft_select *fts)
{
	if (key_code == KEY_UP)
	{
		try_move(0, -1, page, fts);
	}
	else if (key_code == KEY_DOWN)
	{
		try_move(0, 1, page, fts);
	}
	else if (key_code == KEY_LEFT)
	{
		try_move(-1, 0, page, fts);
	}
	else if (key_code == KEY_RIGHT)
	{
		try_move(1, 0, page, fts);
	}
}

