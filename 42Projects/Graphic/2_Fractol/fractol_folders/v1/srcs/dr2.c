/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 06:38:48 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/17 01:35:54 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
/*
int			rand_a_b(int a, int b)
{
	return (rand() % (b - a) + a);
}
*/
void		draw(t_ol *stk)
{
	int		e = -135;
	int		dx = 30;
	int		dy = 40;
	int		color = 16777215;

	e = stk->x2 - stk->x1;
	if (stk->x2 < stk->x1)
		e = stk->x1 - stk->x2;
	dx = e * 2;
	dy = (stk->y2 - stk->y1) * 2;
	if (dy < 0)
		dy = (stk->y1 - stk->y2) * 2;
	while (stk->x1 <= stk->x2)
	{
		if (stk->x1 < 1500 && stk->y1 < 1500 && stk->x1 > 0 && stk->y1 > 0)
			*(unsigned *)(stk->gda + (stk->y1 * stk->szl) +
					(stk->x1 * stk->bpx / 8)) = color;
		if (stk->x2 < stk->x1)
			stk->x1 = stk->x1 - 2;
		stk->x1 = stk->x1 + 1;
		if ((e = e - dy) <= 0)
		{
			if (stk->y1 > stk->y2)
				stk->y1 = stk->y1 - 2;
							stk->y1 = stk->y1 + 1;
					e = e + dx;
		}
	}
}

void		init(char frac, t_ol *stk)
{
	frac = 2;
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, 1000, 800, "Fract'ol");
	stk->img = mlx_new_image(stk->mlx, 1000, 800);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	
	stk->x1 = 62;
	stk->x2 = 47;
	stk->y1 = 75;
	stk->y2 = 95;
	
	draw(stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);
}
