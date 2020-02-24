#include "ft_select.h"

void init_test(t_ft_select *);

int main()
{

	char	key[4];
	/* char	*tmp; */
	int		i = 0;
	t_ft_select	fts;
	init_test(&fts);

	ft_memset(key, 0, 4);
	/* tmp = key; */
	while (key[0] != 'q')
	{
		read(1, key, 3);
		/* if (!strcmp(key, tmp)) */
		/* 	continue ; */
		move_cursor_to(0, i++);
		ft_printf("%2x%2x%2x", key[0], key[1], key[2]);
		/* tmp = key; */
	}
	tcsetattr(0, TCSANOW, &fts.term.oldtio);
}

void init_test(t_ft_select *fts)
{
	char	term_buffer[2048];
	char	*term_type;

	term_type = getenv("TERM");
	tgetent(term_buffer, term_type);
	tcgetattr(0, &fts->term.oldtio);
	fts->term.newtio = fts->term.oldtio;
	fts->term.newtio.c_lflag &= ~ICANON;
	fts->term.newtio.c_lflag &= ~ECHO;
	fts->term.newtio.c_cc[VMIN] = 0;
	fts->term.newtio.c_cc[VTIME] = 2;
	fts->term.newtio.c_oflag &= ~OPOST;
	tcsetattr(0, TCSANOW, &fts->term.newtio);
}
