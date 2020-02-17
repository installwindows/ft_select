/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:10:55 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/17 21:16:25 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_putcap(int c)
{
	return ((int)write(1, &c, 1));
}

int		get_longest_word(t_word *words)
{
	int		lgw;

	lgw = 0;
	while (words)
	{
		if (words->len > lgw)
			lgw = words->len;
		words = words->next;
	}
	return (lgw);
}
