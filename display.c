/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:23:13 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/14 13:09:06 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
	page->book = book;
	set_cases(book, page, index * page->max_words);
	return (page);
}

static void		init_book_pages(t_book *book)
{
	t_page	*head;
	t_page	*prev;
	t_page	**cur;
	int		word_count;
	int		i;

	i = 0;
	head = add_page(book, i++);
	prev = head;
	cur = &head->next;
	word_count = head->word_count;
	while (word_count < book->word_list_size)
	{
		*cur = add_page(book, i++);
		(*cur)->prev = prev;
		prev = *cur;
		cur = &(*cur)->next;
		word_count += prev->word_count;
	}
	book->nb_page = i;
	book->pages = head;
}

static void		init_book(t_book *book, t_ft_select *fts)
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

void			display(t_ft_select *fts)
{
	if (fts->book.pages)
		free_pages(&fts->book, fts->book.pages);
	init_book(&fts->book, fts);
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
		fts->reader.page = find_word_page(fts->book.pages, fts->reader.word);
		set_reader_case(&fts->reader);
	}
	tputs(tgetstr("cl", NULL), 42, ft_putcap);
	display_page(fts->reader.page, fts);
}
