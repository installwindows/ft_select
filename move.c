/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:12:44 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/29 15:11:53 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	change_highlighted(t_case *newb, t_ft_select *fts)
{
	int		modes;

	move_cursor_to(fts->reader.box->x, fts->reader.box->y);
	if (fts->reader.box->word->selected)
		appearance(fts->reader.box->word->value, FTS_REVERSE_VIDEO);
	else
		ft_dprintf(2, "%s", fts->reader.box->word->value);
	move_cursor_to(newb->x, newb->y);
	fts->reader.box = newb;
	fts->reader.word = newb->word;
	modes = FTS_UNDERLINE;
	if (fts->reader.box->word->selected)
		modes |= FTS_REVERSE_VIDEO;
	appearance(fts->reader.box->word->value, modes);
}

static void	move_x(int x, t_page *page, t_ft_select *fts)
{
	int		y;

	y = fts->reader.byi;
	x += fts->reader.bxi;
	if (x > page->word_width)
		x = 0;
	else if (x > page->mid_width && y > page->mid_height)
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
	else if (y > page->mid_height && x > page->mid_width)
		y = 0;
	if (y < 0 && x <= page->mid_width)
		y = page->word_height;
	else if (y < 0 && x > page->mid_width)
		y = page->mid_height;
	fts->reader.byi = y;
}

void		move(int x, int y, t_page *page, t_ft_select *fts)
{
	if (x)
		move_x(x, page, fts);
	if (y)
		move_y(y, page, fts);
	change_highlighted(&page->cases[fts->reader.byi][fts->reader.bxi], fts);
}
