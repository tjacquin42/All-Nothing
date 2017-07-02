/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:04:30 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/09 19:23:40 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init(t_fdf *stk)
{
	stk->color = 16777215;
	stk->hi = 0.25;
	stk->rx = 0;
	stk->ry = 0;
	stk->rz = 0;
	stk->size_win = 1000;
	stk->calx = 0;
	stk->caly = 0;
	stk->zo = 21;
}

int		get_center(t_fdf *stk)
{
	int point;

	point = stk->size_win / 4;
	return (point);
}
