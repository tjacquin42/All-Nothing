/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:04:30 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/10 16:11:06 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		xymax(t_fdf *stk)
{
	if (stk->xmax > stk->ymax)
		return (stk->xmax);
	if (stk->ymax > stk->xmax)
		return (stk->ymax);
	return (stk->xmax);
}

int		xymin(t_fdf *stk)
{
	if (stk->xmax > stk->ymax)
		return (stk->ymax);
	if (stk->ymax > stk->xmax)
		return (stk->xmax);
	return (stk->xmax);
}

void	init(t_fdf *stk)
{
	stk->color = 16777215;
	stk->hi = 1;
	stk->rx = 45;
	stk->ry = -30;
	stk->rz = 10;
	stk->size_win = 1000;
	stk->calx = 0;
	stk->caly = 0;
	stk->zo = stk->size_win / (xymax(stk) + xymin(stk) + 1);
}

int		get_center(t_fdf *stk)
{
	int point;

	point = stk->size_win / 4;
	return (point);
}
