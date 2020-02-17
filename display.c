/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:23:13 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/17 22:46:34 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// set the x, y position of the box on the screen (x and y represent characters position)
static void		set_case(t_case *box, t_word *word, int x, int y, t_book *book)
{
	box->word = word;
	box->x = 
}

// return a 2d array of t_case
static t_case	**get_cases(t_book *book, t_ft_select *fts, int min, int max)
{
	t_case	**cases;
	t_word	*words;
	int		x;
	int		y;

	words = get_word_no(book->word_list, min);
	cases = (t_case**)ft_memalloc(sizeof(t_case*) * book->yw);
	x = 0;
	while (x < book->xw)
		cases[x++] = (t_case*)ft_memalloc(sizeof(t_case) * book->xw);
	// TODO: free cases
	y = 0;
	x = 0;
	while (min < max && words)
	{
		// fill the cases from top to bottom, left to right
		cases[y][x].word = words;
		words = words->next;
		if (x >= book->xw)
		{
			y++;
			x = 0;
		}
	}
	return (cases);
}

static t_page	*add_page(t_book *book, t_ft_select *fts, int index)
{
	t_page	*page;

	page = (t_page*)ft_memalloc(sizeof(t_page));
	page->max_words = book->xw * book->yw;
	page->page_no = index;
	page->cases = get_cases(book, fts, index * page->max_words, page->max_words);
}

static void init_book_pages(t_book *book, t_ft_select *fts)
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
		page = add_page(book, fts, i++);
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

}

void	init_display(t_ft_select *fts)
{
	init_book(&fts->book, fts);
}
