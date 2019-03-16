/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:49:10 by varnaud           #+#    #+#             */
/*   Updated: 2019/03/16 18:49:33 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
