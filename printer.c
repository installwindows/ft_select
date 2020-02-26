/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:11:33 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/23 00:48:11 by varnaud          ###   ########.fr       */
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
