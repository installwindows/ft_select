/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:11:33 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/10 21:14:26 by varnaud          ###   ########.fr       */
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
	while (*fts->words)
	{
		ft_printf("%s %d\n", (*fts->words)->value, (*fts->words)->len);
		fts->words++;
	}
}
