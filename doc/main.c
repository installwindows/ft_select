#include "ft_select.h"

void	test_move()
{
	// cm: cursor movement
	// tgoto: set params (width and height)
	// tputs: write it out to the term
	tputs(tgoto(tgetstr("cm", NULL), 3, 3), 0, ft_putcap);
	ft_printf("Hello world\n");
}

void	test_moving()
{
	char	key[4];

	ft_memset(key, 0, 4);
	while (key[0] != 'q')
	{
		read(0, &key[0], 1);
		if (key[0] == 27)
		{
			read(0, &key[1], 2);
			// check the key and do stuff I gueess?
			if (is(key, KEY_UP))
				move(KEY_UP);
			if (is(key, KEY_DOWN))
				move(KEY_DOWN);
			if (is(key, KEY_LEFT))
				move(KEY_LEFT);
			if (is(key, KEY_RIGHT))
				move(KEY_RIGHT);
		}
	}
}

int		main(void) {
	struct termios	oldtio;
	t_term			term;

	init_termcap();
	oldtio = initialize_terminal();
	term.width = tgetnum("li");
	term.height = tgetnum("co");
	term.cur.x = 0;
	term.cur.y = 0;

	ft_printf("%dx%d\n", term.width, term.height);
	// Clear screen and put cursor at top left corner
	tputs(tgetstr("cl", NULL), 42, ft_putcap);
	test_move();
	test_moving();
	tcsetattr(0, TCSANOW, &oldtio);
	return 0;
}
