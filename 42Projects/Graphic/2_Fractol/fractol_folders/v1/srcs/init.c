/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 06:38:48 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/23 16:59:42 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
/*
void		draw(t_ol *stk)
{
	int x1 = 10;
//	int x0 = x1;
	int x2 = 800;
	int y1 = 10 + stk->decy;
//	int y0 = y1;
//	int y2 = 800;
	int zn = 0;

	zn = (x1 * x1) + y1;
	ft_putnbr(stk->color);
	while (x1 < x2)
	{
		ft_putnbr(x1);
		*(unsigned *)(stk->gda + ((y1 + zn) * stk->szl) + ((x1 + zn) + stk->decx * stk->bpx / 8)) = stk->color;
		x1++;
		stk->color++;;
	}
	
	while (y1 < y2)
	{
		*(unsigned *)(stk->gda + (y1 * stk->szl) + (x1 + stk->decx * stk->bpx / 8)) = stk->color;
		y1++;
		stk->color++;
	}
	while (x1 > x0)
	{
		*(unsigned *)(stk->gda + (y1 * stk->szl) + (x1 + stk->decx * stk->bpx / 8)) = stk->color;
		x1--;
		stk->color++;
	}
	while (y1 > y0)
	{
		*(unsigned *)(stk->gda + (y1 * stk->szl) + (x1 + stk->decx * stk->bpx / 8)) = stk->color;
		y1--;
		stk->color++;
	}
	
}*/
/*
void		mandel_init(t_ol *stk)
{
	stk->swinx = 1000;
	stk->swiny = 1000;
	stk->decx = 0;
	stk->decy = 0;
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, stk->swinx, stk->swiny, "Fract'ol");
	stk->img = mlx_new_image(stk->mlx, stk->swinx, stk->swiny);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	mandel(stk);
	mlx_hook(stk->win, 2, 3, event, stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);
}

void		julia_init(t_ol *stk)
{
	stk->swinx = 1000;
	stk->swiny = 1000;
	stk->decx = 0;
	stk->decy = 0;
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, stk->swinx, stk->swiny, "Fract'ol");
	stk->img = mlx_new_image(stk->mlx, stk->swinx, stk->swiny);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	julia(stk);
	mlx_hook(stk->win, 2, 3, event, stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);
}

void		init(t_ol *stk)
{
	stk->swinx = 1000;
	stk->swiny = 1000;
	stk->decx = 0;
	stk->decy = 0;
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, stk->swinx, stk->swiny, "Fract'ol");
	stk->img = mlx_new_image(stk->mlx, stk->swinx, stk->swiny);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	//draw(stk);
	square(stk);
	mlx_hook(stk->win, 2, 3, event, stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);
}*/
