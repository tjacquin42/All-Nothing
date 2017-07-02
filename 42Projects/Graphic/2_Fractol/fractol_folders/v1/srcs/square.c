/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 05:01:48 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/23 19:49:21 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
/*
   void		mini_square(int dim, t_ol *stk)
   {
   x1 = save 
   while
 *(unsigned *)(stk->gda + ((y1 + stk->decy) * stk->szl) +
 ((x1++ + stk->decx) * stk->bpx / 8)) = stk->color;

 *(unsigned *)(stk->gda + ((y1 + stk->decy) * stk->szl) +
 ((x1++ + stk->decx) * stk->bpx / 8)) = stk->color;

 *(unsigned *)(stk->gda + ((y1 + stk->decy) * stk->szl) +
 ((x1++ + stk->decx) * stk->bpx / 8)) = stk->color;

 *(unsigned *)(stk->gda + ((y1 + stk->decy) * stk->szl) +
 ((x1++ + stk->decx) * stk->bpx / 8)) = stk->color;
 }
 */
void		middle_square(int dim, int center,  t_ol *stk)
{
	int save;
	int save2;
	int x1;
	int y1;

	x1 = center;
	y1 = x1;
	save = x1;
	save2 = x1 + x1;
	if (x1 >= 0 && y1 >= 0 && x1 < stk->swinx && y1 < stk->swiny)
	{
		while (x1 < dim)
			*(unsigned *)(stk->gda + ((y1 + stk->decy) * stk->szl) +
					((x1++ + stk->decx) * stk->bpx / 8)) = stk->color;
		while (y1 < dim)
			*(unsigned *)(stk->gda + ((y1++ + stk->decy) * stk->szl) +
					((x1 + stk->decx) * stk->bpx / 8)) = stk->color;
		while (x1 > (save))
			*(unsigned *)(stk->gda + ((y1 + stk->decy) * stk->szl) +
					((x1-- + stk->decx) * stk->bpx / 8)) = stk->color;
		while (y1 > (save))
			*(unsigned *)(stk->gda + ((y1-- + stk->decy) * stk->szl) +
					((x1 + stk->decx) * stk->bpx / 8)) = stk->color;
	}
}

void		print_square(int x1, int dim, t_ol *stk)
{
	int save;
	int y1;
	int center;
	int more;

	more = 0;
	y1 = x1;
	dim = dim + x1;
	save = x1;
	center = (save + dim) * 10 / 25;
	ft_putnbr(center);
	if (x1 >= 0 && y1 >= 0 && x1 < stk->swinx && y1 < stk->swiny)
	{
		while (y1 < stk->swiny)
		{
			while (x1 < stk->swinx)
			{
				while (x1 < (dim + (dim * more)))
					*(unsigned *)(stk->gda + ((y1 + stk->decy) * stk->szl) +
							((x1++ + stk->decx) * stk->bpx / 8)) = stk->color;
				while (y1 < (dim))
					*(unsigned *)(stk->gda + ((y1++ + stk->decy) * stk->szl) +
							((x1 + stk->decx) * stk->bpx / 8)) = stk->color;
				while (x1 > (save))
					*(unsigned *)(stk->gda + ((y1 + stk->decy) * stk->szl) +
							((x1-- + stk->decx) * stk->bpx / 8)) = stk->color;
				while (y1 > (save))
					*(unsigned *)(stk->gda + ((y1-- + stk->decy) * stk->szl) +
							((x1 + stk->decx) * stk->bpx / 8)) = stk->color;
				more++;
				x1 = x1 + (dim * more);
			}
			x1 = save;
			y1 = y1 + (dim * more);
		}
	}
	dim = (dim / 5) + center;
	middle_square(dim, center, stk);
	//mini_square(save, stk);
}

void		square(t_ol *stk)
{
	print_square(0, 200, stk);
	//print_square(16_sqrt0, 10, stk);
}
