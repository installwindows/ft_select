/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:21:43 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/23 18:07:52 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_space(t_ft_select *fts)
{
	int		modes;

	move_cursor_to(fts->reader.box->x, fts->reader.box->y);
	if (fts->reader.box->word->selected)
		modes = FTS_UNDERLINE;
	else
		modes = FTS_UNDERLINE | FTS_REVERSE_VIDEO;
	fts->reader.box->word->selected = !fts->reader.box->word->selected;
	appearance(fts->reader.box->word->value, modes);
}

void	handle_delete(t_ft_select *fts)
{
	fts->book.word_list = delete_word(fts->book.word_list, fts->reader.box->word);
	fts->book.longest_word = get_longest_word(fts->book.word_list);
	fts->book.word_list_size = get_word_list_size(fts->book.word_list);
}
