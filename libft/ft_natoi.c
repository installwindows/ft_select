/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_natoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 05:02:27 by varnaud           #+#    #+#             */
/*   Updated: 2017/06/02 05:02:49 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_natoi(char *s, int *n)
{
	int		sign;

	if (s == NULL)
		return (1);
	*n = 0;
	sign = 0;
	if (*s == '-')
		sign = *s++;
	while (*s)
	{
		if (!(*s == '0' || *s == '1' || *s == '2' || *s == '3' || *s == '4' ||
			*s == '5' || *s == '6' || *s == '7' || *s == '8' || *s == '9'))
			return (1);
		if (*n && ((!sign && (long)*n * 10 + (*s - '0') > 2147483647) ||
					(sign && (long)*n * 10 + (*s - '0') > 2147483648L)))
			return (1);
		*n = *n * 10 + (*s - '0');
		s++;
	}
	if (sign && *n)
		*n *= -1;
	return (0);
}
