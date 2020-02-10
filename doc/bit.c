#include <stdio.h>

int main()
{
	int		a = 7;
	int		b = 1 << 1;

	printf("%d\n", a &= ~1);
	printf("%d\n", b);
}
