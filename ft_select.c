/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:30:28 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/23 00:49:05 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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

	test_display(fts);
	ft_memset(&key, 0, 4);
	while (key[0] != 'q')
	{
		read(1, &key, 3);
		if (key[0] == '\e')
		{
			// TODO: check movement
			if (is(key, KEY_UP))
				control(KEY_UP, fts->reader.page, fts);
			else if (is(key, KEY_DOWN))
				control(KEY_DOWN, fts->reader.page, fts);
			else if (is(key, KEY_LEFT))
				control(KEY_LEFT, fts->reader.page, fts);
			else if (is(key, KEY_RIGHT))
				control(KEY_RIGHT, fts->reader.page, fts);
			ft_memset(&key, 0, 4);
		}
		check_signals(fts);
	}
}
