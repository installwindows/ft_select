/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 21:13:33 by varnaud           #+#    #+#             */
/*   Updated: 2019/03/16 20:50:39 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


int		read_key(void)
{
	char	key[3];

	read(0, &key[0], 1);
	if (key[0] == '\e')
	{
		read(0, &key[1], 2);
		if (key[1] == '[' || key[1] == 'O')
			return (key[2]);
	}
	return key[0];
}
/*
int		ft_select(t_select *list)
{
	int			key;
	t_select	*cur;

	while (1)
	{
		key = read_key();
		if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == LEY_RIGHT)
			move(key, cur);
		else if (key == KEY_SPACE)
			select(cur);
		else if (key == KEY_ENTER)
			return (0);
		else if (key == KEY_DELETE || key == KEY_BACKSPACE)
			remove(&cur);
		else if (key == KEY_ESCAPE)
			return (1);
		update_display();
	}
}
*/
