/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:39:08 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/29 00:44:26 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		check_termcaps(void)
{
	return
		!tgetstr("us", NULL) ||
		!tgetstr("ue", NULL) ||
		!tgetstr("mr", NULL) ||
		!tgetstr("me", NULL) ||
		!tgetstr("cm", NULL) ||
		!tgetstr("ve", NULL) ||
		!tgetstr("te", NULL) ||
		!tgetstr("ti", NULL) ||
		!tgetstr("vi", NULL) ||
		!tgetstr("cl", NULL);
}

void	underline(char *str)
{
	tputs(tgetstr("us", NULL), 0, ft_putcap);
	ft_dprintf(2, "%s", str);
	tputs(tgetstr("ue", NULL), 0, ft_putcap);
}

void	reverse_video(char *str)
{
	tputs(tgetstr("mr", NULL), 0, ft_putcap);
	ft_dprintf(2, "%s", str);
	tputs(tgetstr("me", NULL), 0, ft_putcap);
}

void	appearance(char *str, int modes)
{
	if (modes & FTS_UNDERLINE)
		tputs(tgetstr("us", NULL), 0, ft_putcap);
	if (modes & FTS_REVERSE_VIDEO)
		tputs(tgetstr("mr", NULL), 0, ft_putcap);
	ft_dprintf(2, "%s", str);
	if (modes & FTS_REVERSE_VIDEO)
		tputs(tgetstr("me", NULL), 0, ft_putcap);
	if (modes & FTS_UNDERLINE)
		tputs(tgetstr("ue", NULL), 0, ft_putcap);
}

void	move_cursor_to(int x, int y)
{
	tputs(tgoto(tgetstr("cm", NULL), x, y), 0, ft_putcap);
}
