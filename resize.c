/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 00:41:47 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/14 13:18:26 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	wait_resize(t_ft_select *fts)
{
	tputs(tgetstr("cl", NULL), 42, ft_putcap);
	ft_printf("Terminal size too small. Waiting for resize...");
	fts->wait_resize = 1;
}

void		handle_resize(t_ft_select *fts)
{
	struct winsize	w;
	int				width;
	int				height;
	int				lgw;

	ioctl(0, TIOCGWINSZ, &w);
	height = w.ws_row;
	width = w.ws_col;
	lgw = fts->book.longest_word;
	if (width > lgw + 2 && height > 3)
	{
		fts->term.height = height;
		fts->term.width = width;
		display(fts);
		fts->wait_resize = 0;
	}
	else
		wait_resize(fts);
}
