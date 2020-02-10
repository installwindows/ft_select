/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:28:56 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/10 19:34:16 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_word	*add_word(char *value)
{
	t_word	*word;

	word = ft_memalloc(sizeof(t_word));
	word->len = ft_strlen(value);
	word->value = value;
	return (word);
}

void	dummy_print_words(t_word **words)
{
	while (*words)
	{
		ft_printf("%s %d\n", (*words)->value, (*words)->len);
		words++;
	}
}

void	free_words(t_word **words)
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

int		main(int argc, char **argv)
{
	t_word		**words;
	t_ft_select	fts;
	int		i;
	
	ft_memset(&fts, 0, sizeof(t_ft_select));
	if (argc > 1)
	{
		words = ft_memalloc(sizeof(t_word*) * argc);
		i = 0;
		while (--argc)
		{
			words[i] = add_word(*++argv);
			if (words[i]->len > fts.longest_word)
				fts.longest_word = words[i]->len;
			i++;
		}
		fts.words = words;
		ft_printf("Longest word len: %d\n", fts.longest_word);
		dummy_print_words(words);
		free_words(words);
	}
	return (0);
}
