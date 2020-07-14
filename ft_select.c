/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:30:28 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/14 15:25:03 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	control(int key_code, t_page *page, t_ft_select *fts, char *key)
{
	if (key_code == KEY_UP)
		move(0, -1, page, fts);
	else if (key_code == KEY_DOWN)
		move(0, 1, page, fts);
	else if (key_code == KEY_LEFT)
		move(-1, 0, page, fts);
	else if (key_code == KEY_RIGHT)
		move(1, 0, page, fts);
	else if (key_code == KEY_SPACE)
		handle_space(fts);
	else if (key_code & (KEY_BACKSPACE | KEY_DELETE))
		handle_delete(fts);
	else if (key_code == KEY_PAGE_UP)
		handle_page_up(fts);
	else if (key_code == KEY_PAGE_DOWN)
		handle_page_down(fts);
	ft_memset(key, 0, 4);
}

static int	is(const char *input, int key_code, t_ft_select *fts)
{
	if (key_code == KEY_UP)
		return (!ft_strcmp(input, fts->keys.up) ||
				!ft_strcmp(input, T_T_KEY_UP));
	else if (key_code == KEY_DOWN)
		return (!ft_strcmp(input, fts->keys.down)
				|| !ft_strcmp(input, T_T_KEY_DOWN));
	else if (key_code == KEY_LEFT)
		return (!ft_strcmp(input, fts->keys.left)
				|| !ft_strcmp(input, T_T_KEY_LEFT));
	else if (key_code == KEY_RIGHT)
		return (!ft_strcmp(input, fts->keys.right)
				|| !ft_strcmp(input, T_T_KEY_RIGHT));
	else if (key_code == KEY_SPACE)
		return (!ft_strcmp(input, " "));
	else if (key_code == KEY_BACKSPACE)
		return (!ft_strcmp(input, "\x7F"));
	else if (key_code == KEY_DELETE)
		return (!ft_strcmp(input, "\x7e\x5b\x33"));
	else if (key_code == KEY_PAGE_UP)
		return (!ft_strcmp(input, "\x7e\x5b\x35"));
	else if (key_code == KEY_PAGE_DOWN)
		return (!ft_strcmp(input, "\x7e\x5b\x36"));
	return (0);
}

static void	parse_escape_key(char *key, t_ft_select *fts)
{
	if (is(key, KEY_UP, fts))
		control(KEY_UP, fts->reader.page, fts, key);
	else if (is(key, KEY_DOWN, fts))
		control(KEY_DOWN, fts->reader.page, fts, key);
	else if (is(key, KEY_LEFT, fts))
		control(KEY_LEFT, fts->reader.page, fts, key);
	else if (is(key, KEY_RIGHT, fts))
		control(KEY_RIGHT, fts->reader.page, fts, key);
	else if (key[1] == '\0')
		clean_exit(fts);
}

static void	parse_key(char *key, t_ft_select *fts)
{
	if (key[0] == '\0')
		return ;
	if (key[0] == '\e')
		parse_escape_key(key, fts);
	else if (key[0] == 'j')
		control(KEY_DOWN, fts->reader.page, fts, key);
	else if (key[0] == 'k')
		control(KEY_UP, fts->reader.page, fts, key);
	else if (key[0] == 'h')
		control(KEY_LEFT, fts->reader.page, fts, key);
	else if (key[0] == 'l')
		control(KEY_RIGHT, fts->reader.page, fts, key);
	else if (is(key, KEY_SPACE, fts))
		control(KEY_SPACE, fts->reader.page, fts, key);
	else if (is(key, KEY_BACKSPACE, fts))
		control(KEY_DELETE, fts->reader.page, fts, key);
	else if (is(key, KEY_DELETE, fts))
		control(KEY_DELETE, fts->reader.page, fts, key);
	else if (is(key, KEY_PAGE_UP, fts))
		control(KEY_PAGE_UP, fts->reader.page, fts, key);
	else if (is(key, KEY_PAGE_DOWN, fts))
		control(KEY_PAGE_DOWN, fts->reader.page, fts, key);
	else if (key[0] == '\n')
		return_exit(fts);
}

void		ft_select(t_ft_select *fts)
{
	char	key[4];

	set_terminal(fts);
	init_keys(fts);
	handle_resize(fts);
	ft_memset(key, 0, 4);
	while (key[0] != 'q')
	{
		read(0, key, 3);
		if (!fts->wait_resize)
			parse_key(key, fts);
		else if (key[0] == '\e')
			break ;
		check_signals(fts);
	}
}
