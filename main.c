/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:28:56 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/26 23:52:21 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


void	clean_exit(t_ft_select *fts)
{
	// TODO: free more stuff
	free_words(fts->word_list);
	reset_terminal(fts);
	exit(0);
}

void	return_exit(t_ft_select *fts)
{
	t_word	*word;
	int		i;

	reset_terminal(fts);
	word = fts->word_list;
	i = 0;
	while (word)
	{
		if (word->selected)
			ft_printf("%s%s", i++ ? " " : "", word->value);
		word = word->next;
	}
	exit(0);
	/* clean_exit(fts); */
}

void	test_tty(void)
{
	//isatty, ttyname, ttyslot
	int slot = ttyslot();
	int i = 0;
	char c = 0;
	char *in = ttyname(1);
	int fd = open(in, O_RDONLY);

	move_cursor_to(0, ++i);
	ft_dprintf(2, "fd: %d isatty: %d\n", fd, isatty(fd));
	move_cursor_to(0, ++i);
	ft_dprintf(2, "ttyslot: %d\n", slot);
	move_cursor_to(0, ++i);
	ft_dprintf(2, "fd: 0 name: %s %s", ttyname(0), isatty(0) ? "is a tty" : "");
	move_cursor_to(0, ++i);
	ft_dprintf(2, "fd: 1 name: %s %s", ttyname(0), isatty(1) ? "is a tty" : "");
	move_cursor_to(0, ++i);
	ft_dprintf(2, "fd: 2 name: %s %s", ttyname(0), isatty(2) ? "is a tty" : "");
	while (c != 'q')
		read(slot, &c, 1);
}

int		main(int argc, char **argv)
{
	t_ft_select	fts;
	
	/* char c = 0; */
	/* ft_printf("%d\n", getpid()); */
	/* while (c != 'q') */
	/* 	read(1,&c,1); */
	if (argc > 1)
	{
		ft_memset(&fts, 0, sizeof(t_ft_select));
		fts.word_list = create_words_list(argc, argv);
		fts.book.longest_word = get_longest_word(fts.word_list);
		init_signals();
		if (init_termcap(&fts))
			clean_exit(&fts);
		initialize_terminal(&fts);
		test_tty();
		/* ft_select(&fts); */
		clean_exit(&fts);
	}
	return (0);
}
