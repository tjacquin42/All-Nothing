#include "../includes/fdf.h"

int		key_change(int a, fdf_t *stk)
{
	//static int y = 0;
	if (a == 126)
		stk->x1 = stk->x1 + 20;
	if (a == 125)
		stk->x1 = stk->x1 - 20;
	ft_putnbr(stk->x1);
	ft_putchar('\n');
	//mlx_clear_window(stk->mlx, stk->win);
	return (0);
}
