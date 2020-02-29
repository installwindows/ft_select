/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 01:35:52 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/29 15:27:40 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		set_case(t_case *box, t_word *word, int x, int y, t_book *book)
{
	box->word = word;
	box->x = x * book->longest_word + (x + 1) * 2;
	box->y = (y * 2) + 1;
	box->active = 1;
}

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
		set_case(&page->cases[y][x], *words, x, y, page->book);
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

