/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:30:28 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/23 21:47:01 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	control(int key_code, t_page *page, t_ft_select *fts, char *key)
{
	if (key_code == KEY_UP)
	{
		move(0, -1, page, fts);
	}
	else if (key_code == KEY_DOWN)
	{
		move(0, 1, page, fts);
	}
	else if (key_code == KEY_LEFT)
	{
		move(-1, 0, page, fts);
	}
	else if (key_code == KEY_RIGHT)
	{
		move(1, 0, page, fts);
	}
	else if (key_code == KEY_SPACE)
	{
		handle_space(fts);
	}
	else if (key_code == KEY_DELETE)
	{
		handle_delete(fts);
	}
	else if (key_code == KEY_PAGE_UP)
	{
		handle_page_up(fts);
	}
	else if (key_code == KEY_PAGE_DOWN)
	{
		handle_page_down(fts);
	}
	ft_memset(key, 0, 4);
}

static int	is(const char *input, int key_code)
{
	if (key_code == KEY_UP)
		return !strcmp(input, T_KEY_UP) || !strcmp(input, T_T_KEY_UP);
	else if (key_code == KEY_DOWN)
		return !strcmp(input, T_KEY_DOWN) || !strcmp(input, T_T_KEY_DOWN);
	else if (key_code == KEY_LEFT)
		return !strcmp(input, T_KEY_LEFT) || !strcmp(input, T_T_KEY_LEFT);
	else if (key_code == KEY_RIGHT)
		return !strcmp(input, T_KEY_RIGHT) || !strcmp(input, T_T_KEY_RIGHT);
	else if (key_code == KEY_SPACE)
		return !strcmp(input, " ");
	else if (key_code == KEY_DELETE)
		return !strcmp(input, "\x7F");
	else if (key_code == KEY_PAGE_UP)
		return !strcmp(input, "\x1b\x5b\x35");
	else if (key_code == KEY_PAGE_DOWN)
		return !strcmp(input, "\x7e\x5b\x36");
	return (0);
}

static void	parse_key(char *key, t_ft_select *fts)
{
	if (key[0] == '\e')
	{
		if (is(key, KEY_UP))
			control(KEY_UP, fts->reader.page, fts, key);
		else if (is(key, KEY_DOWN))
			control(KEY_DOWN, fts->reader.page, fts, key);
		else if (is(key, KEY_LEFT))
			control(KEY_LEFT, fts->reader.page, fts, key);
		else if (is(key, KEY_RIGHT))
			control(KEY_RIGHT, fts->reader.page, fts, key);
	}
	else if (is(key, KEY_SPACE))
		control(KEY_SPACE, fts->reader.page, fts, key);
	else if (is(key, KEY_DELETE))
		control(KEY_DELETE, fts->reader.page, fts, key);
	else if (is(key, KEY_PAGE_UP))
		control(KEY_PAGE_UP, fts->reader.page, fts, key);
	else if (is(key, KEY_PAGE_DOWN))
		control(KEY_PAGE_DOWN, fts->reader.page, fts, key);
}

void		ft_select(t_ft_select *fts)
{
	char	key[4];

	display(fts);
	ft_memset(key, 0, 4);
	while (key[0] != 'q')
	{
		read(1, key, 3);
		parse_key(key, fts);
		check_signals(fts);
	}
}
