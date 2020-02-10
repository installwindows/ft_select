#include <unistd.h>
#include <stdio.h>

int		main()
{
	int		fildes;
	int		tty;
	char	*name;

	tty = ttyslot();
	fildes = 1;
	name = ttyname(fildes);
	printf("tty?: %d\nname: %s\nttyslot: %d\n", isatty(fildes), name, tty);
}
