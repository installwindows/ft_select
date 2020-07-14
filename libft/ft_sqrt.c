/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:13:26 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/17 19:02:34 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double n)
{
	double	low;
	double	mid;
	double	high;
	int		i;

	low = 0;
	high = n;
	i = 0;
	while (i < 100)
	{
		mid = (low + high) / 2;
		if (mid * mid == n)
			return mid;
		else if (mid * mid > n)
			high = mid;
		else
			low = mid;
		i++;
	}
	return (mid);
}
