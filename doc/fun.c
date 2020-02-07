#include "ft_select.h"

int		is(const char *input, int key_code)
{
	if (key_code == KEY_UP)
		return !strcmp(input, T_KEY_UP) || !strcmp(input, T_T_KEY_UP);
	if (key_code == KEY_DOWN)
		return !strcmp(input, T_KEY_DOWN) || !strcmp(input, T_T_KEY_DOWN);
	if (key_code == KEY_LEFT)
		return !strcmp(input, T_KEY_LEFT) || !strcmp(input, T_T_KEY_LEFT);
	if (key_code == KEY_RIGHT)
		return !strcmp(input, T_KEY_RIGHT) || !strcmp(input, T_T_KEY_RIGHT);
	return (0);
}

void	move(int key_code)
{
	if (key_code == KEY_UP)
		ft_printf("↑");
	if (key_code == KEY_DOWN)
		ft_printf("↓");
	if (key_code == KEY_LEFT)
		ft_printf("←");
	if (key_code == KEY_RIGHT)
		ft_printf("→");
}
