/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:26:23 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/23 18:03:28 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_page	*find_word_page(t_page *pages, t_word *word)
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

void	set_reader_case(t_reader *reader)
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
			}
			j++;
		}
		i++;
	}
}
