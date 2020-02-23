/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:39:08 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/23 02:01:52 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	underline(char *str)
{
	tputs(tgetstr("us", NULL), 0, ft_putcap);
	ft_printf("%s", str);
	tputs(tgetstr("ue", NULL), 0, ft_putcap);
}

void	reverse_video(char *str)
{
	tputs(tgetstr("mr", NULL), 0, ft_putcap);
	ft_printf("%s", str);
	tputs(tgetstr("me", NULL), 0, ft_putcap);
}

void	appearance(char *str, int modes)
{
	if (modes & FTS_UNDERLINE)
		tputs(tgetstr("us", NULL), 0, ft_putcap);
	if (modes & FTS_REVERSE_VIDEO)
		tputs(tgetstr("mr", NULL), 0, ft_putcap);
	ft_printf("%s", str);
	if (modes & FTS_REVERSE_VIDEO)
		tputs(tgetstr("me", NULL), 0, ft_putcap);
	if (modes & FTS_UNDERLINE)
		tputs(tgetstr("ue", NULL), 0, ft_putcap);
}

void	move_cursor_to(int x, int y)
{
	tputs(tgoto(tgetstr("cm", NULL), x, y), 0, ft_putcap);
}
