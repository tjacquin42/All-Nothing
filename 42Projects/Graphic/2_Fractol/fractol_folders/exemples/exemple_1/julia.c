/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:33:51 by dchristo          #+#    #+#             */
/*   Updated: 2016/07/11 15:45:44 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_j(t_env *e, double x0, double y0)
{
	double		x1;
	double		y1;
	double		sco;
	double		i;

	i = -1.0;
	sco = exp(-sqrt(x0 * x0 + y0 * y0));
	while (++i < e->iter && (x0 + y0) < 4.0)
	{
		x1 = x0;
		y1 = y0;
		x0 = x1 * x1 - y1 * y1 + e->xs;
		y0 = 2.0 * x1 * y1 + e->ys;
		sco += exp(-sqrt(x0 * x0 + y0 * y0));
	}
	if (e->theme < 3)
		i = ft_mix(i, sco, 1.0);
	e->color = palette(i, (e->theme > 2 ? e->theme - 3 : e->theme));
	pixel_put(e);
}

void	julia(t_env *e)
{
	e->y = -1;
	while ((e->y += 1) < e->img.height)
	{
		e->x = -1;
		while ((e->x += 1) < e->img.width)
			calculate_j(e, scaledx(e, e->x), scaledy(e, e->y));
	}
}
