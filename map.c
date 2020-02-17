/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:54:16 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/16 23:21:30 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	set_book(t_ft_select *fts)
{
	t_book	*book;

	book = (t_book*)malloc(sizeof(t_book*))0, page->page_no; // TODO: free it
	book->words = fts->words_list;
	/* book->cols_max = fts->term.width / (fts->lgw + FTS_MARGIN); */
	/* book->rows_max = fts->term.height / 2 - 1; */
	book->cols = fts->term.width / (fts->lgw + FTS_MARGIN);
	book->rows = fts->term.height / 2 - 1;
	book->pages = fts->nbw / (book->cols + book->rows); //TODO: change nbw name
	fts->book = book;
}

void	set_cases(t_ft_select *fts, t_page *page)
{
	t_case	**cases;
	t_case	*box;
	t_word	*list;
	int		i;
	
	cases = (t_case**)malloc(sizeof(t_case**));
	list = seek_words(fts->words, page->page_no * page->max_words);
	i = 0;
	while (i < 

}

t_page	*get_page(t_ft_select *fts, int page_no, int word_start)
{
	t_page	*page;

	page = (t_page*)malloc(sizeof(t_page*)); // TODO: free it
	page->page_no = page_no;
	page->cols = 4;
	page->rows = 4;
	page->max_words = page->cols * page->rows;
	set_cases(fts, page);
}

void	fill_cases(t_ft_select *fts)
{

}
