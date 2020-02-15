/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:38:41 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/15 19:01:20 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	initialize_terminal(t_ft_select *fts)
{
	tcgetattr(0, &fts->term.oldtio);
	fts->term.newtio = fts->term.oldtio;
	fts->term.newtio.c_lflag &= ~ICANON;
	fts->term.newtio.c_lflag &= ~ECHO;
	fts->term.newtio.c_cc[VMIN] = 0;
	fts->term.newtio.c_cc[VTIME] = 1;
	fts->term.newtio.c_oflag &= ~OPOST;
	tcsetattr(0, TCSANOW, &fts->term.newtio);
	tputs(tgetstr("ti", NULL), 42, ft_putcap);
	tputs(tgetstr("vi", NULL), 42, ft_putcap);
	fts->term.height = tgetnum("li");
	fts->term.width = tgetnum("co");
	tputs(tgetstr("cl", NULL), 42, ft_putcap);
}

static void	check_termcaps(t_ft_select *fts)
{
	// should check that the magic words I use are available
	fts->term.mw[0] = 0;
}

int		init_termcap(t_ft_select *fts)
{
	char	term_buffer[2048];
	char	*term_type;
	int		r;
	int		err;

	err = 0;
	term_type = getenv("TERM");
	if (term_type == NULL)
		err = ft_fprintf(2, "Environment variable TERM not set.\n");
	r = tgetent(term_buffer, term_type);
	if (r < 0)
		err = ft_fprintf(2, "Could not access the termcap database\n");
	else if (r == 0)
		err = ft_fprintf(2, "Terminal type `%s` is not defined.\n", term_type);
	check_termcaps(fts);
	return (err);
}

void	reset_terminal(t_ft_select *fts)
{
	tputs(tgetstr("ve", NULL), 42, ft_putcap);
	tputs(tgetstr("te", NULL), 42, ft_putcap);
	tcsetattr(0, TCSANOW, &fts->term.oldtio);
}
