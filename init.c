/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:38:41 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/14 13:14:22 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	raw_terminal_mode(void)
{
	struct termios	tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ECHO | ICANON);
	tattr.c_oflag &= ~OPOST;
	tattr.c_cc[VMIN] = 0;
	tattr.c_cc[VTIME] = 2;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	return ;
}

static void	default_terminal_mode(void)
{
	struct termios	tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag |= (ECHO | ICANON);
	tattr.c_oflag |= OPOST;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	return ;
}

static int	init_termcap(void)
{
	char	term_buffer[2048];
	char	*term_type;
	int		r;
	int		err;

	err = 0;
	term_type = getenv("TERM");
	if (term_type == NULL)
		err = ft_dprintf(2, "Environment variable TERM not set.\n");
	r = tgetent(term_buffer, term_type);
	if (r < 0)
		err = ft_dprintf(2, "Could not access the termcap database\n");
	else if (r == 0)
		err = ft_dprintf(2, "Terminal type `%s` is not defined.\n", term_type);
	check_termcaps();
	return (err);
}

void		reset_terminal(void)
{
	tputs(tgetstr("ve", NULL), 42, ft_putcap);
	tputs(tgetstr("te", NULL), 42, ft_putcap);
	default_terminal_mode();
}

void		set_terminal(t_ft_select *fts)
{
	if (init_termcap())
	{
		ft_dprintf(STDERR_FILENO, "There is some missing termcap.");
		clean_exit(fts);
	}
	raw_terminal_mode();
	tputs(tgetstr("ti", NULL), 42, ft_putcap);
	tputs(tgetstr("vi", NULL), 42, ft_putcap);
}
