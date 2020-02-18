/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:22:24 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/18 23:36:35 by varnaud          ###   ########.fr       */
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

t_word	*delete_word(t_word *list, t_word *word)
{
	t_word	*head;

	head = list;
	if (head == word)
	{
		head = list->next;
		free(word);
		return (head);
	}
	while (list->next)
	{
		if (list->next == word)
		{
			list->next = word->next;
			free(word);
			break ;
		}
		list = list->next;
	}
	return (head);
}

t_word	*get_word_no(t_word *list, int no)
{
	if (!no)
		return (list);
	else if (no > 0)
	{
		while (no-- && list)
			list = list->next;
		return (list);
	}
	return (NULL);
}

int		get_word_list_size(t_word *list)
{
	int		i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
