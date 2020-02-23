/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:21:43 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/23 20:49:59 by varnaud          ###   ########.fr       */
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
	t_word	*new_cur;

	new_cur = NULL;
	if (fts->reader.word->next)
		new_cur = fts->reader.word->next;
	else if (fts->reader.word->prev)
		new_cur = fts->reader.word->prev;
	else
		clean_exit(fts);
	delete_word(&fts->word_list, fts->reader.word);
	fts->reader.word = new_cur;
	display(fts);
}
