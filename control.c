/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:11:08 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/23 00:38:25 by varnaud          ###   ########.fr       */
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
	ft_printf("%s", fts->reader.box->word->value);
	move_cursor_to(new->x, new->y);
	fts->reader.box = new;
	fts->reader.word = new->word;
	tputs(tgetstr("so", NULL), 0, ft_putcap);
	ft_printf("%s", fts->reader.box->word->value);
	tputs(tgetstr("se", NULL), 0, ft_putcap);
}

static void	move_x(int x, t_page *page, t_ft_select *fts)
{
	int		y;

	y = fts->reader.byi;
	x += fts->reader.bxi;
	if (x > page->word_width)
		x = 0;
	if (x > page->mid_width && y > page->mid_height)
		x = 0;
	if (x < 0 && y <= page->mid_height)
		x = page->word_width;
	else if (x < 0 && y > page->mid_height)
		x = page->mid_width;
	fts->reader.bxi = x;
}

static void	move_y(int y, t_page *page, t_ft_select *fts)
{
	int		x;

	x = fts->reader.bxi;
	y += fts->reader.byi;
	if (y > page->word_height)
		y = 0;
	if (y > page->mid_height && x > page->mid_width)
		y = 0;
	if (y < 0 && x <= page->mid_width)
		y = page->word_height;
	else if (y < 0 && x > page->mid_width)
		y = page->mid_height;
	fts->reader.byi = y;
}

static void	try_move(int x, int y, t_page *page, t_ft_select *fts)
{
	if (x)
		move_x(x, page, fts);
	if (y)
		move_y(y, page, fts);
	change_highlighted(&page->cases[fts->reader.byi][fts->reader.bxi], fts);
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

