#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <termcap.h>

#define SKEY_UP "\e[A"
#define SKEY_DOWN "\e[B"
#define SKEY_RIGHT "\e[C"
#define SKEY_LEFT "\e[D"

#define KEY_UP (1 << 0)
#define KEY_DOWN (1 << 1)
#define KEY_RIGHT (1 << 2)
#define KEY_LEFT (1 << 3)

int		check_key(const char *key, int code, char *buffer)
{
	int		r = 0;

	if (code & KEY_UP && !(code &= ~KEY_UP))
		if (!strcmp(key, SKEY_UP) || !strcmp(key, tgetstr("ku", &buffer)))
			r = 1;
	if (code & KEY_DOWN && !(code &= ~KEY_DOWN))
		if (!strcmp(key, SKEY_DOWN) || !strcmp(key, tgetstr("kd", &buffer)))
			r = 1;
	if (code & KEY_RIGHT && !(code &= ~KEY_RIGHT))
		if (!strcmp(key, SKEY_RIGHT) || !strcmp(key, tgetstr("kr", &buffer)))
			r = 1;
	if (code & KEY_LEFT && !(code &= ~KEY_LEFT))
		if (!strcmp(key, SKEY_LEFT) || !strcmp(key, tgetstr("kl", &buffer)))
			r = 1;
	return r;//(code ? (r && check_key(key, code, buffer)) : r);
}

int		main(void) {
	char	c;
	char	key[4];
	char	*buffer;
	buffer = malloc(2048);
	static struct termios oldtio, newtio;

	tgetent(buffer, getenv("TERM"));
	printf("%s", getenv("TERM"));
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

	printf("Give text:\n");
	fflush(stdout);
	while (1) {
		read(0, &key[0], 1);

		if (key[0] == 27) {
			key[0] = 27;
			read(0, &key[1], 1);
			read(0, &key[2], 1);
			key[3] = 0;
			if (check_key(key, KEY_UP, buffer))
				printf("UP\n");
			else if (check_key(key, KEY_DOWN, buffer))
				printf("DOWN\n");
			else if (check_key(key, KEY_RIGHT, buffer))
				printf("RIGHT\n");
			else if (check_key(key, KEY_LEFT, buffer))
				printf("LEFT\n");
			else
				printf("\\e%c%c\n", key[1], key[2]);
			continue;
		}
		else if (key[0] == 'q') {
			break;
		}
		else
			printf(" %c ", key[0]);
	}
	printf("\n");
	tcsetattr(0, TCSANOW, &oldtio);

	return 0;
}
