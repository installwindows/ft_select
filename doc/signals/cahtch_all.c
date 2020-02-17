#include <termios.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}

int			g_signals[32];

void		signal_handler(int sig)
{
	g_signals[sig] = 1;
}

void		sigint_handler(int sig)
{
	printf("handling SIGINT (%d)\n", sig);
	g_signals[sig] = 1;
}

void		sigtstp_handler(int sig)
{
	printf("handling SIGTSTP (%d)\n", sig);
	g_signals[sig] = 1;
}

void		sigcont_handler(int sig)
{
	printf("handling SIGCONT (%d)\n", sig);
	g_signals[sig] = 1;
}

void		sigquit_handler(int sig)
{
	printf("handling SIGQUIT (%d)\n", sig);
	g_signals[sig] = 1;
}

void		sigwinch_handler(int sig)
{
	printf("handling SIGWINCH (%d)\n", sig);
	g_signals[sig] = 1;
}

static void	init_signals(void)
{
	int		i;

	ft_memset(&g_signals, 0, sizeof(int) * 32);
	i = 1;
	while (i < 32)
	{
		printf("ignoring sig %2d\n", i);
		signal(i, SIG_IGN);
		i++;
	}
	signal(SIGINT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGWINCH, signal_handler);
	/* signal(SIGINT, sigint_handler); */
	/* signal(SIGTSTP, sigtstp_handler); */
	/* signal(SIGCONT, sigcont_handler); */
	/* signal(SIGQUIT, sigquit_handler); */
	/* signal(SIGWINCH, sigwinch_handler); */
}

void		check_signals(int value)
{
	if (g_signals[SIGINT])
	{
		printf("handling SIGINT\n");
		g_signals[SIGINT] = 0;
		exit(0);
	}
	if (g_signals[SIGTSTP])
	{
		printf("handling SIGTSTP\n");
		g_signals[SIGTSTP] = 0;
	}
	if (g_signals[SIGCONT])
	{
		printf("handling SIGCONT\n");
		g_signals[SIGCONT] = 0;
	}
	if (g_signals[SIGQUIT])
	{
		printf("handling SIGQUIT\n");
		g_signals[SIGQUIT] = 0;
	}
	if (g_signals[SIGWINCH])
	{
		printf("handling SIGWINCH\n");
		g_signals[SIGWINCH] = 0;
	}
	printf("\t%d\n", value);
}

int main()
{
	init_signals();

	struct termios o;
	struct termios n;
	tcgetattr(0, &o);
	n = o;
	n.c_lflag &= ~ICANON;
	n.c_cc[VMIN] = 0;
	n.c_cc[VTIME] = 1;
	tcsetattr(0, TCSANOW, &n);
	char c = 0;
	while (c != 'q')
	{
		read(1, &c, 1);
		check_signals(c);
	}
	tcsetattr(0, TCSANOW, &o);
}

