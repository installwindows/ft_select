/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:23:13 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/19 00:12:37 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// set the x, y position of the box on the screen (x and y represent characters position)
static void		set_case(t_case *box, t_word *word, int x, int y, t_book *book)
{
	box->word = word;
	box->x = x * book->longest_word + 1;
	box->y = y;
	box->active = 1;
}

// return a 2d array of t_case
static t_case	**get_cases(t_book *book, int min, int max)
{
	t_case	**cases;
	t_word	*words;
	int		x;
	int		y;

	words = get_word_no(book->word_list, min);
	cases = (t_case**)ft_memalloc(sizeof(t_case*) * book->yw);
	y = 0;
	while (y < book->yw)
		cases[y++] = (t_case*)ft_memalloc(sizeof(t_case) * book->xw);
	// TODO: free cases
	x = 0;
	// fill the cases from top to bottom, left to right
	while (x < book->xw)
	{
		y = 0;
		while (y < book->yw)
		{
			if (min++ >= max || !words)
				return (cases);
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
	page->max_words = (book->xw * book->yw) / book->longest_word;
	page->page_no = index;
	page->cases = get_cases(book, index * page->max_words, page->max_words);
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
			prev = page->next;
		}
		wc += book->word_list_size;
	}
	book->pages = head;
}

static void	init_book(t_book *book, t_ft_select *fts)
{
	ft_memset(book, 0, sizeof(t_book));
	book->xw_max = fts->term.width / (fts->lgw + FTS_MARGIN);
	book->yw_max = fts->term.height / 2 - 1;
	book->xw = book->xw_max;
	book->yw = book->yw_max;
	book->longest_word = get_longest_word(fts->words_list);
	book->word_list = fts->words_list;
	book->word_list_size = get_word_list_size(fts->words_list);
	init_book_pages(book);
}

void	init_display(t_ft_select *fts)
{
	init_book(&fts->book, fts);
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
				/* tputs(tgoto(tgetstr("cm", NULL), box->x, box->y), 0, ft_putcap); */
				ft_printf("%s", box->word->value);
			}
			j++;
		}
		i++;
	}
}

void	test_display(t_ft_select *fts)
{
	init_display(fts);
	display_page(fts->book.pages, fts);
}
