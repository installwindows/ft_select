/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:21:57 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/13 17:31:00 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:22:24 by varnaud           #+#    #+#             */
/*   Updated: 2020/07/13 17:20:00 by varnaud          ###   ########.fr       */
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

t_word	*create_words_list(char **word_list)
{
	t_word	*head;
	t_word	*prev;
	t_word	**cur;

	head = add_word(*word_list);
	word_list++;
	prev = head;
	cur = &head->next;
	while (*word_list)
	{
		*cur = add_word(*word_list);
		(*cur)->prev = prev;
		prev = *cur;
		cur = &(*cur)->next;
		word_list++;
	}
	return (head);
}

void	delete_word(t_word **list, t_word *word)
{
	if (*list == word)
	{
		*list = word->next;
		word->next->prev = NULL;
	}
	else if (word->next == NULL)
	{
		word->prev->next = NULL;
	}
	else
	{
		word->prev->next = word->next;
		word->next->prev = word->prev;
	}
	free(word);
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
