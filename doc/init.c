#include "ft_select.h"

struct termios	initialize_terminal(void)
{
	struct termios	oldtio;
	struct termios	newtio;

	tcgetattr(0, &oldtio);
	newtio = oldtio;
	newtio.c_lflag &= ~ICANON;
	newtio.c_lflag &= ~ECHO;
	newtio.c_cc[VMIN] = 1;
	newtio.c_cc[VTIME] = 0;
	newtio.c_oflag &= ~OPOST;
	tcsetattr(0, TCSANOW, &newtio);
	return (oldtio);
}

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

int		ft_putcap(int c)
{
	return ((int)write(1, &c, 1));
}
