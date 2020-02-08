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

void	move(int key_code, t_term *term)
{
	if (key_code == KEY_UP)
	{
		move_cursor(0, -1, term);
		ft_printf("↑");
	}
	if (key_code == KEY_DOWN)
	{
		move_cursor(0, 1, term);
		ft_printf("↓");
	}
	if (key_code == KEY_LEFT)
	{
		move_cursor(-1, 0, term);
		ft_printf("←");
	}
	if (key_code == KEY_RIGHT)
	{
		move_cursor(1, 0, term);
		ft_printf("→");
	}
}

void	move_cursor(int x, int y, t_term *term)
{
	x = x + term->cur.x;
	y = y + term->cur.y;
	if (x > term->width)
		x = 0;
	else if (x < 0)
		x = term->width;
	if (y > term->height)
		y = 0;
	else if (y < 0)
		y = term->height;
	tputs(tgoto(tgetstr("cm", NULL), x, y), 0, ft_putcap);
	term->cur.x = x;
	term->cur.y = y;
}
