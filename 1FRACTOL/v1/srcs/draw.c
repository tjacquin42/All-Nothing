/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 06:38:48 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/13 11:43:44 by tjacquin         ###   ########.fr       */
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
	int color = 16777214;
	int x;
	int x2;
	int y;
	int y2;

	x = -24;
	x2 = 24;
	y = -15;
	y2 = 15;
	while (x < 319)
	{
		while (x < 199)
		{
			*(unsigned *)(stk->gda + ((y + (y2 - y)/200 * y) * stk->szl) +
					((x + (x2 - x) /320 * x) * stk->bpx / 8)) = color;
			x++;
		}
		y++;
	}
}

void		init(int frac, t_ol *stk)
{
	frac = 2;
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, 1000, 800, "Fract'ol");
	stk->img = mlx_new_image(stk->mlx, 1000, 800);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	draw(stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);
}
