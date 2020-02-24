/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:28:56 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/24 22:00:24 by varnaud          ###   ########.fr       */
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
		init_signals();
		init_termcap(&fts);
		initialize_terminal(&fts);
		ft_select(&fts);
		clean_exit(&fts);
	}
	return (0);
}
