/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:39:35 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/15 18:53:59 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	signal_handler(int sig)
{
	g_signals[sig] = 1;
}

static void	sigtstp_handler(t_ft_select *fts)
{
	char	k[2];

	k[0] = fts->term.newtio.c_cc[VSUSP];
	k[1] = '\0';
	tcsetattr(0, TCSANOW, &fts->term.oldtio);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, k);
}

void		check_signals(t_ft_select *fts)
{
	if (g_signals[SIGINT])
		clean_exit(fts);
	if (g_signals[SIGTSTP])
	{
		g_signals[SIGTSTP] = 0;
		sigtstp_handler(fts);
	}
	if (g_signals[SIGCONT])
	{
		g_signals[SIGCONT] = 0;
		signal(SIGTSTP, signal_handler);
		tcsetattr(0, TCSANOW, &fts->term.newtio);
		tputs(tgetstr("cl", NULL), 42, ft_putcap);
	}
	if (g_signals[SIGQUIT])
		clean_exit(fts);
	if (g_signals[SIGWINCH])
	{
		g_signals[SIGWINCH] = 0;
	}
}

void		init_signals(void)
{
	int		i;

	ft_memset(&g_signals, 0, sizeof(int) * 32);
	i = 1;
	while (i < 32)
	{
		signal(i, SIG_IGN);
		i++;
	}
	signal(SIGINT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGWINCH, signal_handler);
}
