/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:49:10 by varnaud           #+#    #+#             */
/*   Updated: 2019/03/16 23:59:47 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_termcap(void)
{
	char	term_buffer[2048];
	char	*term_type;
	int		r;

	term_type = getenv("TERM");
	if (term_type == NULL)
	{
		ft_fprintf(2, "Environment variable TERM not set.\n");
		exit(1);
	}
	r = tgetent(term_buffer, term_type);
	if (r < 0)
	{
		ft_fprintf(2, "Could not access the termcap database\n");
		exit(1);
	}
	else if (r == 0)
	{
		ft_fprintf(2, "Terminal type `%s` is not defined.\n", term_type);
		exit(1);
	}
}

t_select	*init_list(int argc, char **argv)
{
	int			i;
	t_select	*head;
	t_select	*prev;
	t_select	*cur;

	head = NULL;
	cur = NULL;
	prev = NULL;
	i = 1;
	while (i < argc)
	{
		cur = (t_select*)ft_memalloc(sizeof(t_select));
		cur->arg = argv[i];
		cur->selected = 0;
		if (!head)
			head = cur;
		if (prev)
			prev->next = cur;
		cur->prev = prev;
		prev = cur;
		i++;
	}
	return (head);
}

int		ft_putcap(int c)
{
	return ((int)write(1, &c, 1));
}
ssize_t	putstr(const char *str)
{
	ssize_t		len;

	len = ft_strlen(str);
	if (len > 0)
		write(0, str, len);
	return len;
}
void	print_list(t_select *list)
{
//	int		width = tgetnum("co");
	int		height = tgetnum("li");
	t_cur	cur;
	
	cur.x = 0;
	cur.y = 0;
	tputs(tgetstr("cl", NULL), height, ft_putcap);
	tputs(tgoto(tgetstr("cm", NULL), cur.x, cur.y), 1, ft_putcap);
	while (list)
	{
		putstr(list->arg);
		putstr(" ");
		list = list->next;
	}
}

int		main(int argc, char **argv)
{
	t_select	*list;

	if (argc < 2)
		return 0;
	list = init_list(argc, argv);
	/*
	while (list)
	{
		printf("%s\n", list->arg);
		if (list->prev)
			printf("prev: %s\n", list->prev->arg);
		list = list->next;
	}
	*/
	init_termcap();
	print_list(list);
	read(0, &argc, 1);
	//tputs(tgetstr("cl", NULL), 11, putchar);
	//tputs(tgoto(tgetstr("cm", NULL), 5, 5), 1, ft_putcap);
	//ft_printf("%dx%d\n", tgetnum("co"), tgetnum("li"));
}
