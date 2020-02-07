#include "ft_select.h"

void	test_move()
{
	char c;
	// cm: cursor movement
	// tgoto: set params (width and height)
	// tputs: write it out to the term
	tputs(tgoto(tgetstr("cm", NULL), 3, 3), 0, ft_putcap);
	ft_printf("Hello world\n");
	read(0, &c, 1);
}

void	test_moving()
{
	char	key[4];

	key[3] = 0;
	read(0, &key[0], 1);
	if (key[0] == 27)
	{
		read(0, &key[1], 2);
		// check the key and do stuff I gueess?
		if (is(key, "UP"))
			move("UP");
	}
}

int		main(void) {
	struct termios	oldtio;
	int				screen_width;
	int				screen_height;
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
