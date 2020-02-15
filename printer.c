/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:11:33 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/15 15:44:26 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
		ft_printf("%s %d\n", fts->words[i]->value, fts->words[i]->len);
		i++;
		tputs(tgoto(tgetstr("cm", NULL), 0, i), 0, ft_putcap);
	}
}
