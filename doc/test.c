#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <termcap.h>
#include "libft.h"
#include "ft_select.h"

#define SKEY_UP "\e[A"
#define SKEY_DOWN "\e[B"
#define SKEY_RIGHT "\e[C"
#define SKEY_LEFT "\e[D"

#define KEY_UP (1 << 0)
#define KEY_DOWN (1 << 1)
#define KEY_RIGHT (1 << 2)
#define KEY_LEFT (1 << 3)

void	init_termcap(void) {
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
	/*
	newtio.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
                           | INLCR | IGNCR | ICRNL | IXON);
	newtio.c_oflag &= ~OPOST;
	newtio.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	newtio.c_cflag &= ~(CSIZE | PARENB);
	newtio.c_cflag |= CS8;
	*/
	tcsetattr(0, TCSANOW, &newtio);
	return (oldtio);
}

int		ft_putcap(int c)
{
	return ((int)write(1, &c, 1));
}

int		check_key(const char *key, int code)
{
	int		r = 0;

	if (code & KEY_UP && !(code &= ~KEY_UP))
		if (!strcmp(key, SKEY_UP) || !strcmp(key, tgetstr("ku", NULL)))
			r = 1;
	if (code & KEY_DOWN && !(code &= ~KEY_DOWN))
		if (!strcmp(key, SKEY_DOWN) || !strcmp(key, tgetstr("kd", NULL)))
			r = 1;
	if (code & KEY_RIGHT && !(code &= ~KEY_RIGHT))
		if (!strcmp(key, SKEY_RIGHT) || !strcmp(key, tgetstr("kr", NULL)))
			r = 1;
	if (code & KEY_LEFT && !(code &= ~KEY_LEFT))
		if (!strcmp(key, SKEY_LEFT) || !strcmp(key, tgetstr("kl", NULL)))
			r = 1;
	return r;//(code ? (r && check_key(key, code, buffer)) : r);
}

void	loop_input(void)
{
	char			c;
	char			key[4];

	while (1) {
		read(0, &key[0], 1);
		//tputs(tgoto(tgetstr("cm", NULL), 0, 0), 0, ft_putcap);
		//tputs(tgetstr("cl", NULL), 0, ft_putcap);
		tputs(tgetstr("cr", NULL), 0, ft_putcap);
		tputs(tgetstr("ce", NULL), 0, ft_putcap);

		if (key[0] == 27) {
			key[0] = 27;
			read(0, &key[1], 2);
			//read(0, &key[2], 1);
			key[3] = 0;
			if (check_key(key, KEY_UP))
				ft_printf("UP");
			else if (check_key(key, KEY_DOWN))
				ft_printf("DOWN");
			else if (check_key(key, KEY_RIGHT))
				ft_printf("RIGHT");
			else if (check_key(key, KEY_LEFT))
				ft_printf("LEFT");
			else
				ft_printf("\\e%c%c\n", key[1], key[2]);
			continue;
		}
		else if (key[0] == 'q') {
			break;
		}
		else
			printf(" %c ", key[0]);
	}
}

void	update_display(void)
{
	
}

int		main(void) {
	struct termios	oldtio;

	init_termcap();
	oldtio = initialize_terminal();
	loop_input();
	tcsetattr(0, TCSANOW, &oldtio);
	return 0;
}
