/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 21:29:34 by varnaud           #+#    #+#             */
/*   Updated: 2017/04/28 22:26:42 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <term.h>
#include "libft.h"

typedef struct	s_term
{
	char		buffer[2048];
	int			type;
	char		area[2048];
}				t_term;

#endif
