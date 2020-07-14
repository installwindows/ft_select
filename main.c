/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:28:56 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/14 13:34:44 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	free_words(t_word *words)
{
	t_word	*tmp;

	while (words)
	{
		tmp = words->next;
		free(words);
		words = tmp;
	}
}

static void	free_fts(t_ft_select *fts)
{
	free_pages(&fts->book, fts->book.pages);
	free_words(fts->word_list);
}

void		clean_exit(t_ft_select *fts)
{
	reset_terminal(fts);
	free_fts(fts);
	exit(0);
}

void		return_exit(t_ft_select *fts)
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
	free_fts(fts);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_ft_select	fts;

	if (argc > 1)
	{
		init_signals();
		ft_memset(&fts, 0, sizeof(t_ft_select));
		fts.word_list = create_words_list(++argv);
		fts.book.longest_word = get_longest_word(fts.word_list);
		ft_select(&fts);
		clean_exit(&fts);
	}
	return (0);
}
