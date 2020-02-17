/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:28:56 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/17 17:23:44 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


void	clean_exit(t_ft_select *fts)
{
	free_words(fts->words_list);
	reset_terminal(fts);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_ft_select	fts;
	
	if (argc > 1)
	{
		ft_memset(&fts, 0, sizeof(t_ft_select));
		fts.words_list = create_words_list(argc, argv);
		init_signals();
		init_termcap(&fts);
		initialize_terminal(&fts);
		dummy_print_words_list(fts.words_list);
		while (argc != 'q')
			read(1, &argc, 1);
		/* ft_select(&fts); */
		clean_exit(&fts);
	}
	return (0);
}
