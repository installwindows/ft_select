#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <termcap.h>

int		main(void) {
	char	c;
	char	*buffer;
	buffer = malloc(2048);
	static struct termios oldtio, newtio;

	tgetent(buffer, getenv("TERM"));
	printf("%s", getenv("TERM"));
	tcgetattr(0, &oldtio);
	newtio = oldtio;
	/*
	newtio.c_lflag &= ~ICANON;
	newtio.c_lflag &= ~ECHO;
	newtio.c_cc[VMIN] = 1;
	newtio.c_cc[VTIME] = 0;
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
		read(0, &c, 1);

		if (c == 27) {
			char key[4];
			key[0] = 27;
			read(0, &c, 1);
			key[1] = c;
			read(0, &c, 1);
			key[2] = c;
			key[3] = 0;
			char * k_up = tgetstr("ku", &buffer);

			if (strcmp(key, k_up) == 0)
				printf("UP\n");

			if (strcmp(key, "\e[B") == 0)
				printf("DOWN\n");
			continue;
		}
		if (c == 'q') {
			break;
		}
	}
	printf("\n");
	tcsetattr(0, TCSANOW, &oldtio);

	return 0;
}
