/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:30:28 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/15 20:15:57 by varnaud          ###   ########.fr       */
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
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 0, ft_putcap);
	/* ft_printf("nbwc: %d x nbwr %d x nbp %d", nbwc, nbwr, nbp); */
	basic_printer(fts, nbwc, nbwr, nbp);
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
			update_display(fts);
			ft_memset(&key, 0, 4);
		}
		check_signals(fts);
	}
}
