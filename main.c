/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:28:56 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/17 17:19:51 by varnaud          ###   ########.fr       */
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

static void		free_words(t_word *words)
{
	t_word	*tmp;

	while (words)
	{
		tmp = words->next;
		free(words);
		words = tmp;
	}
}

void			clean_exit(t_ft_select *fts)
{
	free_words(fts->words_list);
	reset_terminal(fts);
	exit(0);
}

static t_word	*create_words_list(int argc, char **argv)
{
	t_word	*head;
	t_word	*prev;

	head = NULL;
	if (argc-- > 1)
	{
		head = add_word(*++argv);
		prev = head;
		while (--argc)
		{
			prev->next = add_word(*++argv);
			prev = prev->next;
		}
	}
	return (head);
}

int				main(int argc, char **argv)
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
