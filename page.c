/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:26:23 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/14 19:41:34 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		free_pages(t_book *book, t_page *pages)
{
	t_page	*del;
	int		i;

	while (pages)
	{
		i = 0;
		while (i < book->yw)
			free(pages->cases[i++]);
		free(pages->cases);
		del = pages;
		pages = pages->next;
		free(del);
	}
}

t_page		*find_word_page(t_page *pages, t_word *word)
{
	int		i;
	t_word	*w;

	while (pages)
	{
		w = pages->word_list;
		i = 0;
		while (w && i++ < pages->word_count)
		{
			if (word == w)
				return (pages);
			w = w->next;
		}
		pages = pages->next;
	}
	return (NULL);
}

void		set_reader_case(t_reader *reader)
{
	int		i;
	int		j;

	i = 0;
	while (i <= reader->page->word_height)
	{
		j = 0;
		while (j <= reader->page->word_width)
		{
			if (reader->page->cases[i][j].word == reader->word)
			{
				reader->bxi = j;
				reader->byi = i;
				reader->box = &reader->page->cases[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	print_word(t_ft_select *fts, t_case *box)
{
	if (box->active)
	{
		move_cursor_to(box->x, box->y);
		if (box->word->selected && fts->reader.box == box)
			appearance(box->word->value, FTS_REVERSE_VIDEO | FTS_UNDERLINE);
		else if (box->word->selected)
			reverse_video(box->word->value);
		else if (fts->reader.box == box)
			underline(box->word->value);
		else
			ft_dprintf(2, "%s", box->word->value);
	}
}

void		display_page(t_page *page, t_ft_select *fts)
{
	int		i;
	int		j;

	i = 0;
	while (i < fts->book.yw)
	{
		j = 0;
		while (j < fts->book.xw)
		{
			print_word(fts, &page->cases[i][j]);
			j++;
		}
		i++;
	}
	move_cursor_to(fts->term.width - ft_numlen(fts->book.nb_page) * 2 - 4,
													fts->term.height - 1);
	ft_dprintf(2, "%d / %d", page->page_no + 1, fts->book.nb_page);
}
