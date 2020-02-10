#include "ft_select.h"

int		ft_putcap(int c)
{
	return ((int)write(1, &c, 1));
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

void	print_command_name(const char *cmd)
{
	int		i = 0;
	char	*c = tgetstr(cmd, NULL);

	for (i = 0; i < ft_strlen(c); i++)
	{
		ft_putnbr(c[i]);
		ft_putchar(':');
		ft_putchar(c[i]);
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	init_termcap();
	if (argc > 1)
		print_command_name(argv[1]);
}
