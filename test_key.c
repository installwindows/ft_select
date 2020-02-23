#include "ft_select.h"

int main()
{

	char	key[4];
	char	*tmp;
	int		i = 0;
	t_ft_select	fts;
	init_termcap(&fts);
	initialize_terminal(&fts);

	ft_memset(key, 0, 4);
	tmp = key;
	while (key[0] != 'q')
	{
		read(1, key, 3);
		/* if (!strcmp(key, tmp)) */
		/* 	continue ; */
		move_cursor_to(0, i++);
		ft_printf("%2x%2x%2x", key[0], key[1], key[2]);
		tmp = key;
	}
	reset_terminal(&fts);
}
