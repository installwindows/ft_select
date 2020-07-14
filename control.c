/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:21:43 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/14 20:27:54 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_space(t_ft_select *fts)
{
	int		modes;

	move_cursor_to(fts->reader.box->x, fts->reader.box->y);
	if (!fts->reader.box->word->selected)
		modes = FTS_REVERSE_VIDEO;
	else
		modes = FTS_CLEAR;
	fts->reader.box->word->selected = !fts->reader.box->word->selected;
	appearance(fts->reader.box->word->value, modes);
	move_to_next_word(fts);
}

void	handle_delete(t_ft_select *fts)
{
	t_word	*new_cur;

	new_cur = NULL;
	if (fts->reader.word->next)
		new_cur = fts->reader.word->next;
	else if (fts->reader.word->prev)
		new_cur = fts->reader.word->prev;
	else
		clean_exit(fts);
	delete_word(&fts->word_list, fts->reader.word);
	fts->reader.word = new_cur;
	display(fts);
}

void	handle_page_up(t_ft_select *fts)
{
	t_page	*next;

	next = fts->reader.page->next ? fts->reader.page->next : fts->book.pages;
	fts->reader.page = next;
	fts->reader.box = &fts->reader.page->cases[0][0];
	fts->reader.bxi = 0;
	fts->reader.byi = 0;
	fts->reader.word = fts->reader.box->word;
	display(fts);
}

void	handle_page_down(t_ft_select *fts)
{
	t_page	*prev;

	if (fts->reader.page->prev)
		prev = fts->reader.page->prev;
	else
	{
		prev = fts->reader.page;
		while (prev->next)
			prev = prev->next;
	}
	fts->reader.page = prev;
	fts->reader.box = &fts->reader.page->cases[0][0];
	fts->reader.bxi = 0;
	fts->reader.byi = 0;
	fts->reader.word = fts->reader.box->word;
	display(fts);
}
