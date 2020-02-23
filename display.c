/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:23:13 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/23 20:17:07 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// set the x, y position of the box on the screen (x and y represent characters position)
static void		set_case(t_case *box, t_word *word, int x, int y, t_book *book)
{
	box->word = word;
	box->x = x * book->longest_word + (x + 1) * 2;
	box->y = (y * 2) + 1;
	box->active = 1;
}

// return a 2d array of t_case
static t_case	**get_cases(t_book *book, t_page *page, int min, int max)
{
	t_case	**cases;
	t_word	*words;
	int		x;
	int		y;

	words = get_word_no(book->word_list, min);
	page->word_list = words;
	cases = (t_case**)ft_memalloc(sizeof(t_case*) * book->yw);
	y = 0;
	while (y < book->yw)
		cases[y++] = (t_case*)ft_memalloc(sizeof(t_case) * book->xw);
	x = 0;
	while (x < book->xw)
	{
		y = 0;
		while (y < book->yw)
		{
			if (min++ >= max || !words)
			{
				page->mid_height = y - 1;
				page->mid_width = x - 1;
				page->word_width = x;
				page->word_height = x > 1 ? book->yw - 1 : y;
				page->word_count = min;
				return (cases);
			}
			set_case(&cases[y][x], words, x, y, book);
			words = words->next;
			y++;
		}
		x++;
	}
	return (cases);
}

static t_page	*add_page(t_book *book, int index)
{
	t_page	*page;

	page = (t_page*)ft_memalloc(sizeof(t_page));
	page->max_words = book->xw * book->yw;
	page->page_no = index;
	page->word_width = book->xw - 1;
	page->word_height = book->yw - 1;
	page->mid_width = book->xw - 1;
	page->mid_height = book->yw - 1;
	page->word_count = page->max_words;
	page->cases = get_cases(book, page, index * page->max_words, page->max_words);
	return (page);
}

static void init_book_pages(t_book *book)
{
	t_page	*page;
	t_page	*head;
	t_page	*prev;
	int		wc;
	int		i;

	wc = 0;
	i = 0;
	head = NULL;
	while (wc < book->word_list_size)
	{
		page = add_page(book, i++);
		if (head == NULL)
		{
			head = page;
			prev = head;
		}
		else
		{
			prev->next = page;
			prev = page;
		}
		wc += page->word_count;
	}
	book->nb_page = i;
	book->pages = head;
}

static void	init_reader(t_ft_select *fts)
{
	if (fts->reader.page == NULL)
	{
		fts->reader.page = fts->book.pages;
		fts->reader.box = &fts->book.pages->cases[0][0];
		fts->reader.word = fts->book.pages->cases[0][0].word;
		fts->reader.bxi = 0;
		fts->reader.byi = 0;
	}
	else
	{
		fts->reader.page = find_word_page(fts->reader.page, fts->reader.word);
		set_reader_case(&fts->reader);
	}
}

static void	init_book(t_book *book, t_ft_select *fts)
{
	ft_memset(book, 0, sizeof(t_book));
	book->word_list = fts->word_list;
	book->longest_word = get_longest_word(book->word_list);
	book->word_list_size = get_word_list_size(book->word_list);
	book->xw_max = fts->term.width / (book->longest_word + FTS_MARGIN);
	book->yw_max = fts->term.height / 2 - 1;
	book->xw = book->xw_max;
	book->yw = book->yw_max;
	init_book_pages(book);
}

void	init_display(t_ft_select *fts)
{
	init_book(&fts->book, fts);
	init_reader(fts);
}

void	display_page(t_page *page, t_ft_select *fts)
{
	int		i;
	int		j;
	t_case	*box;

	i = 0;
	while (i < fts->book.yw)
	{
		j = 0;
		while (j < fts->book.xw)
		{
			box = &page->cases[i][j];
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
					ft_printf("%s", box->word->value);
			}
			j++;
		}
		i++;
	}
}

void	display(t_ft_select *fts)
{
	init_display(fts);
	display_debug_info(fts);
	display_page(fts->reader.page, fts);
}
