/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:28:56 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/16 02:00:01 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_word	*add_word(char *value)
{
	t_word	*word;

	word = ft_memalloc(sizeof(t_word));
	word->len = ft_strlen(value);
	word->value = value;
	return (word);
}

static void		free_words(t_word **words)
{
	t_word	**tmp;

	tmp = words;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(words);
}

void			clean_exit(t_ft_select *fts)
{
	free_words(fts->words);
	reset_terminal(fts);
	exit(0);
}

int				main(int argc, char **argv)
{
	t_word		**words;
	t_ft_select	fts;
	int		i;
	
	if (argc > 1)
	{
		ft_memset(&fts, 0, sizeof(t_ft_select));
		words = ft_memalloc(sizeof(t_word*) * argc);
		i = 0;
		while (--argc)
		{
			words[i] = add_word(*++argv);
			if (words[i]->len > fts.lgw)
				fts.lgw = words[i]->len;
			i++;
		}
		fts.nbw = i;
		fts.words = words;
		fts.current_word = words[0];
		fts.current_word->selected = 1;
		init_signals();
		init_termcap(&fts);
		initialize_terminal(&fts);
		ft_select(&fts);
		reset_terminal(&fts);
	}
	return (0);
}
