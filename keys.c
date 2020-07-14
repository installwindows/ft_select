/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:39:30 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/14 15:13:41 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_keys(t_ft_select *fts)
{
	fts->keys.up = tgetstr("ku", NULL);
	fts->keys.down = tgetstr("kd", NULL);
	fts->keys.left = tgetstr("kl", NULL);
	fts->keys.right = tgetstr("kr", NULL);
	fts->keys.back = tgetstr("kb", NULL);
	fts->keys.del = tgetstr("kD", NULL);
	fts->keys.page_up = tgetstr("kN", NULL);
	fts->keys.page_down = tgetstr("kP", NULL);
}
