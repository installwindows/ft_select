/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:39:08 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/23 01:41:02 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	underline(char *str)
{
	tputs(tgetstr("us", NULL), 0, ft_putcap);
	ft_printf("%s", str);
	tputs(tgetstr("ue", NULL), 0, ft_putcap);
}
