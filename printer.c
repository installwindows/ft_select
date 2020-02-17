/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:11:33 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/17 17:07:42 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	dummy_print_words_list(t_word *words)
{
	int		i;

	i = 0;
	while (words)
	{
		tputs(tgoto(tgetstr("cm", NULL), FTS_MARGIN, i + 3), 0, ft_putcap);
		ft_printf("%s %d\n", words->value, words->len);
		words = words->next;
		i++;
	}
}

void	dummy_print_words(t_word **words)
{
	while (*words)
	{
		ft_printf("%s %d\n", (*words)->value, (*words)->len);
		words++;
	}
}

void	print_words(t_ft_select *fts)
{
	int		i;

	i = 0;
	while (fts->words[i])
	{
		tputs(tgoto(tgetstr("cm", NULL), FTS_MARGIN, i + 3), 0, ft_putcap);
		ft_printf("%s %d\n", fts->words[i]->value, fts->words[i]->len);
		i++;
	}
}

void	basic_printer(t_ft_select *fts, int wc, int wr, int nbp)
{
	int		i;
	int		j;
	int		w;
	
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 0, ft_putcap);
	w = 0;
	i = 0;
	while (i < wc)
	{
		j = 0;
		while (j < wr)
		{
			tputs(tgoto(tgetstr("cm", NULL), fts->lgw * i + 1, j), 0, ft_putcap);
			if (fts->words[w]->selected)
				tputs(tgetstr("so", NULL), 0, ft_putcap);
			ft_printf("%s", fts->words[w]->value);
			if (fts->words[w]->selected)
				tputs(tgetstr("se", NULL), 0, ft_putcap);
			w++;
			if (w >= fts->nbw)
				return ;
			j++;
		}
		i++;
	}
	if (nbp) // TODO: pagination
		nbp = 0;
}
