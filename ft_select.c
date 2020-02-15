/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:30:28 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/15 18:47:14 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select(t_ft_select *fts)
{
	print_words(fts);
	char c;

	c = 0;
	while (c != 'q')
	{
		read(1, &c, 1);
		check_signals(fts);
	}
}
