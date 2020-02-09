#include <termios.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

typedef struct s_sig
{
    void (*sigtstp_original_handler)(int);
} t_sig;

t_sig g_sig;

static void sigint_handler(int sig)
{
    printf("Sig %d received.\n", sig);
}

static void sigtstp_handler(int sig)
{
    struct termios t;
    tcgetattr(0, &t);
    char k[2];
    k[0] = t.c_cc[VSUSP];
    k[1] = 0;
    printf("Entering tstp\n");

    signal(SIGTSTP, SIG_DFL);

    /* write(0, k, 2); */
    ioctl(0, TIOCSTI, k);

    /* signal(SIGTSTP, sigtstp_handler); */
    printf("Leaving tstp\n");
}

static void sigcont_handler(int sig)
{
    printf("Continuing...\n");
    signal(SIGTSTP, sigtstp_handler);
}

int main()
{
    char c = 0;
    struct termios t;
    tcgetattr(0, &t);

    signal(SIGTSTP, sigtstp_handler);
    signal(SIGCONT, sigcont_handler);

    signal(SIGINT, sigint_handler);
    signal(SIGWINCH, sigint_handler);
    signal(SIGTERM, sigint_handler);
    printf("VSUSP: %d\n", t.c_cc[VSUSP]);
    /* char k[2]; */
    /* k[0] = t.c_cc[VSUSP]; */
    /* k[1] = 0; */
    /* write(0, k, 2); */
    /* ioctl(0, TIOCSTI, k); */
    while (c != 'q')
    {
        printf("Main\n");
        read(1, &c, 1);
    }
}
