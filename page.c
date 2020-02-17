/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:26:23 by varnaud           #+#    #+#             */
/*   Updated: 2020/02/17 22:48:16 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
 * if the screen resize, the what page should we be on?
 * allow scrolling then? if we keep pagination, then the new page after resize would be
 * recalculated. We calculate which page the current word should be in and we display it
 */

/*
 * t_cur: word position in the list
 *        x and y position in the case array?
 */

/* dynamic longest word? */


/*
 * Ok, fixing the case length to the list largest word. Not recalculating it for every page...
 * Will be easier this way.
 */

/*
 * With this simplification, what need to be done:
 * keep track of which page we're on
 * display that page
 */

// get page_info for all pages
// if resize, we check the current word position in the words_list and figure out which page it's
// now on;
t_page_info	*generate_page_info(t_ft_select *fts)
{
	t_page_info	p_i;
	int			i;
	int			wc;

	i = 0;
	while (1)
	{
		p_i.index = i;
		calculate_page_info(&p_i, fts);
		i++;
		wc += p_i->nb_words;
	}
}
