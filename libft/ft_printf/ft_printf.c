/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 13:45:00 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/14 21:23:24 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

static int	read_args(int fd, char *format, va_list *args, int nbprint)
{
	char	*fmt;

	if ((fmt = ft_strchr(format, '%')) == NULL)
	{
		nbprint += ft_putstr_fd(format, fd);
		return (nbprint);
	}
	else
	{
		ft_putnstr_fd(format, fmt - format, fd);
		nbprint += fmt - format;
		fmt++;
		nbprint += print_arg(fd, &fmt, args);
		format = fmt;
	}
	return (read_args(fd, format, args, nbprint));
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int			r;

	va_start(args, format);
	r = read_args(1, (char*)format, &args, 0);
	va_end(args);
	return (r);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	int			r;

	va_start(args, format);
	r = read_args(fd, (char*)format, &args, 0);
	va_end(args);
	return (r);
}

/*
** The va_copy is a workaround for the following warning:
** expected ‘__va_list_tag (*)[1]’ but argument is of type ‘__va_list_tag **’
*/

int			ft_vdprintf(int fd, const char *format, va_list args)
{
	va_list	cpy;
	int		r;

	va_copy(cpy, args);
	r = read_args(fd, (char*)format, &cpy, 0);
	va_end(cpy);
	return (r);
}
