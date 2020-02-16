/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:54:16 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/16 23:13:21 by varnaud          ###   ########.fr       */
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
	int		max_words;
	
	cases = (t_case**)malloc(sizeof(t_case**));
	max_words = fts->book->cols * fts->book->rows;

}

t_page	*get_page(t_ft_select *fts, int page_no, int word_start)
{
	t_page	*page;

	page = (t_page*)malloc(sizeof(t_page*)); // TODO: free it
	page->page_no = page_no;
	page->start = word_start;
	set_cases(fts, page);
	
}

void	fill_cases(t_ft_select *fts)
{

}
