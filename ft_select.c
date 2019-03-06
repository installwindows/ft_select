/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 21:13:33 by varnaud           #+#    #+#             */
/*   Updated: 2019/03/06 07:53:14 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_putcap(int c)
{
	return ((int)write(1, &c, 1));
}

void	init_termcap(void)
{
	char	term_buffer[2048];
	char	*term_type;
	int		r;

	term_type = getenv("TERM");
	if (term_type == NULL)
	{
		ft_fprintf(2, "Environment variable TERM not set.\n");
		exit(1);
	}
	r = tgetent(term_buffer, term_type);
	if (r < 0)
	{
		ft_fprintf(2, "Could not access the termcap database\n");
		exit(1);
	}
	else if (r == 0)
	{
		ft_fprintf(2, "Terminal type `%s` is not defined.\n", term_type);
		exit(1);
	}
}

int		main(void)
{
	init_termcap();
	//tputs(tgetstr("cl", NULL), 11, putchar);
	tputs(tgoto(tgetstr("cm", NULL), 5, 5), 1, ft_putcap);
	ft_printf("%dx%d\n", tgetnum("co"), tgetnum("li"));
}
