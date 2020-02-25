/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 00:41:47 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/25 01:41:54 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	wait_resize(t_ft_select *fts)
{
	char	c;

	tputs(tgetstr("cl", NULL), 42, ft_putcap);
	ft_printf("Terminal size too small. Waiting for resize...");
	c = 0;
	while (c != 'q' && c != '\e')
	{
		read(1, &c, 1);
		check_signals(fts);
		if (fts->term.width > fts->book.longest_word + 2 && fts->term.height > 2)
			break ;
	}
}

void	handle_resize(t_ft_select *fts)
{
	// check if size is ok
	// reset fts->term size
	// display again
	struct winsize	w;
	int				width;
	int				height;
	int				lgw;

    ioctl(0, TIOCGWINSZ, &w);
	height = w.ws_row;
	width = w.ws_col;
	lgw = fts->book.longest_word;
	if (width > lgw + 2 && height > 2)
	{
		fts->term.height = height;
		fts->term.width = width;
		display(fts);
	}
	else
		wait_resize(fts);
}

