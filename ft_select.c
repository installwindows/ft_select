/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:30:28 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/16 02:10:54 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		update_display(t_ft_select *fts)
{
	int		nbwc;
	int		nbwr;
	int		nbp;
	// check terminal size
	// if ok, display words
	// if not, return
	if (fts->term.width < (fts->lgw + FTS_MARGIN) || fts->term.height < 2)
		return (-1);
	nbwc = fts->term.width / (fts->lgw + FTS_MARGIN);
	nbwr = fts->term.height / 2 - 1;
	nbp = fts->nbw / (nbwc + nbwr);
	fts->display.wc = nbwc;
	fts->display.wr = nbwr;
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 0, ft_putcap);
	/* ft_printf("nbwc: %d x nbwr %d x nbp %d", nbwc, nbwr, nbp); */
	basic_printer(fts, nbwc, nbwr, nbp);
	return (0);
}

int		is(const char *input, int key_code)
{
	if (key_code == KEY_UP)
		return !strcmp(input, T_KEY_UP) || !strcmp(input, T_T_KEY_UP);
	else if (key_code == KEY_DOWN)
		return !strcmp(input, T_KEY_DOWN) || !strcmp(input, T_T_KEY_DOWN);
	else if (key_code == KEY_LEFT)
		return !strcmp(input, T_KEY_LEFT) || !strcmp(input, T_T_KEY_LEFT);
	else if (key_code == KEY_RIGHT)
		return !strcmp(input, T_KEY_RIGHT) || !strcmp(input, T_T_KEY_RIGHT);
	return (0);
}

void	ft_select(t_ft_select *fts)
{
	char	key[4];

	ft_memset(&key, 0, 4);
	while (key[0] != 'q')
	{
		read(1, &key, 3);
		if (key[0] == '\e')
		{
			// TODO: check movement
			// c * nwr + r
			if (is(key, KEY_UP))
				basic_move(KEY_UP, fts);
			else if (is(key, KEY_DOWN))
				basic_move(KEY_DOWN, fts);
			else if (is(key, KEY_LEFT))
				basic_move(KEY_LEFT, fts);
			else if (is(key, KEY_RIGHT))
				basic_move(KEY_RIGHT, fts);
			update_display(fts);
			/* ft_printf("%x%x%x", key[0],key[1],key[2]); */
			ft_memset(&key, 0, 4);
		}
		check_signals(fts);
	}
}
