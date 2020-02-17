/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:22:24 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/17 17:24:44 by varnaud          ###   ########.fr       */
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

void	free_words(t_word *words)
{
	t_word	*tmp;

	while (words)
	{
		tmp = words->next;
		free(words);
		words = tmp;
	}
}

t_word	*create_words_list(int argc, char **argv)
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
