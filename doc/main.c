#include "ft_select.h"

void	test_esc(t_term *term)
{
	char	key[4];
	int		i;

	i = 0;
	ft_memset(key, 0, 4);
	while (key[0] != 'q')
	{
		ft_memset(key, 0, 4);
		read(0, &key[0], 3);
		if (key[0] == '\e')
		{
			if (is(key, KEY_UP))
				move(KEY_UP, term);
			else if (is(key, KEY_DOWN))
				move(KEY_DOWN, term);
			else if (is(key, KEY_LEFT))
				move(KEY_LEFT, term);
			else if (is(key, KEY_RIGHT))
				move(KEY_RIGHT, term);
			else
			{
				// It was either only esc or another key?
				print_status("ESC: %2x %2x %2x (%d)\n", key[1], key[2], key[3], ++i);
			}
		}
	}
}

void	test_move()
{
	// cm: cursor movement
	// tgoto: set params (width and height)
	// tputs: write it out to the term
	tputs(tgoto(tgetstr("cm", NULL), 3, 3), 0, ft_putcap);
	ft_printf("Hello world\n");
}

void	test_moving(t_term *term)
{
	char	key[4];

	ft_memset(key, 0, 4);
	while (key[0] != 'q')
	{
		read(0, &key[0], 1);
		if (key[0] == 27)
		{
			read(0, &key[1], 2);
			if (is(key, KEY_UP))
				move(KEY_UP, term);
			if (is(key, KEY_DOWN))
				move(KEY_DOWN, term);
			if (is(key, KEY_LEFT))
				move(KEY_LEFT, term);
			if (is(key, KEY_RIGHT))
				move(KEY_RIGHT, term);
		}
	}
}

int		main(void) {
	struct termios	oldtio;
	t_term			term;

	init_termcap();
	oldtio = initialize_terminal();
	// Set the terminal into a special mode for full screen
	tputs(tgetstr("ti", NULL), 42, ft_putcap);
	// Make the cursor invisible
	tputs(tgetstr("vi", NULL), 42, ft_putcap);
	term.height = tgetnum("li");
	term.width = tgetnum("co");
	term.cur.x = 0;
	term.cur.y = 0;

	ft_printf("%dx%d\n", term.width, term.height);
	// Clear screen and put cursor at top left corner
	tputs(tgetstr("cl", NULL), 42, ft_putcap);
	/* test_move(); */
	/* test_moving(&term); */
	test_esc(&term);
	// Reset the cursor to visible
	tputs(tgetstr("ve", NULL), 42, ft_putcap);
	// Reset the terminal into nomal mode
	tputs(tgetstr("te", NULL), 42, ft_putcap);
	tcsetattr(0, TCSANOW, &oldtio);
	return 0;
}
