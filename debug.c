/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:39:40 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/14 17:59:12 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	display_debug_info(t_ft_select *fts)
{
	char	c;
	int		i;

	i = 0;
	tputs(tgoto(tgetstr("cm", NULL), 0, i++), 0, ft_putcap);
	ft_printf("pid: %d", getpid());
	tputs(tgoto(tgetstr("cm", NULL), 0, i++), 0, ft_putcap);
	ft_printf("longest_word: %d", fts->book.longest_word);
	tputs(tgoto(tgetstr("cm", NULL), 0, i++), 0, ft_putcap);
	ft_printf("xw, yw: %d, %d", fts->book.xw, fts->book.yw);
	tputs(tgoto(tgetstr("cm", NULL), 0, i++), 0, ft_putcap);
	ft_printf("nb_page: %d", fts->book.nb_page);
	tputs(tgoto(tgetstr("cm", NULL), 0, i++), 0, ft_putcap);
	ft_printf("page 1: ww, wh, mw, mh: %d, %d, %d, %d",
		fts->book.pages->word_width, fts->book.pages->word_height,
		fts->book.pages->mid_width, fts->book.pages->mid_height);
	c = 0;
	while (c != 'q')
		read(1, &c, 1);
	tputs(tgetstr("cl", NULL), 42, ft_putcap);
}
