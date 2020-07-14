/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 01:35:52 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/14 13:04:32 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_case	**init_cases(t_book *book)
{
	t_case	**cases;
	int		y;

	cases = (t_case**)ft_memalloc(sizeof(t_case*) * book->yw);
	y = 0;
	while (y < book->yw)
		cases[y++] = (t_case*)ft_memalloc(sizeof(t_case) * book->xw);
	return (cases);
}

static int		set_column(t_page *page, t_word **words, int x, int *i)
{
	int		y;

	y = 0;
	while (y < page->book->yw)
	{
		if ((*i)++ >= page->max_words || !*words)
		{
			page->mid_height = y - 1;
			page->mid_width = x - 1;
			page->word_width = x;
			page->word_height = x > 0 ? page->book->yw - 1 : y;
			page->word_count = *i;
			return (1);
		}
		page->cases[y][x].word = *words;
		page->cases[y][x].x = x * page->book->longest_word + (x + 1) * 2;
		page->cases[y][x].y = (y * 2) + 1;
		page->cases[y][x].active = 1;
		*words = (*words)->next;
		y++;
	}
	return (0);
}

void			set_cases(t_book *book, t_page *page, int word_index)
{
	t_word	*words;
	int		x;
	int		i;

	words = get_word_no(book->word_list, word_index);
	page->word_list = words;
	page->cases = init_cases(book);
	x = 0;
	i = 0;
	while (x < book->xw)
	{
		if (set_column(page, &words, x, &i))
			return ;
		x++;
	}
}
