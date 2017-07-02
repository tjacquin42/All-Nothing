/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:33:47 by dchristo          #+#    #+#             */
/*   Updated: 2016/09/10 23:15:28 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_press2(int keycode, t_env *e)
{
	double tmp;

	if (keycode == LEFT || keycode == RIGHT)
	{
		tmp = (e->xtop - e->xbot) / 4;
		e->xbot += (keycode == RIGHT ? tmp : -tmp);
		e->xtop += (keycode == RIGHT ? tmp : -tmp);
	}
	else if ((e->iter > 1 && keycode == A) || keycode == D)
		e->iter += (keycode == D ? 35 : -35);
	else if (keycode == S)
		e->stop = 1;
}

int			key_press(int keycode, t_env *e)
{
	double	tmp;

	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == T)
		e->theme += (e->theme == 5 ? -5 : 1);
	else if (keycode == UP || keycode == DOWN)
	{
		tmp = (e->ytop - e->ybot) / 4;
		e->ybot += (keycode == DOWN ? tmp : -tmp);
		e->ytop += (keycode == DOWN ? tmp : -tmp);
	}
	else
		key_press2(keycode, e);
	expose_hook(e);
	return (1);
}

int			mouse2(int x, int y, t_env *e)
{
	if (e->stop == 0)
	{
		e->xs = scaledx(e, x);
		e->ys = scaledy(e, y);
		if (e->ftype == 3)
			e->xs = x;
	}
	expose_hook(e);
	return (1);
}

int			mouse(int button, int x, int y, t_env *e)
{
	double		x1;
	double		y1;

	x1 = scaledx(e, x);
	y1 = scaledy(e, y);
	if (button == 1 || button == 4)
	{
		e->xbot = x1 + ((e->xbot - x1) / 2);
		e->xtop = e->xtop + ((x1 - e->xtop) / 2);
		e->ybot = y1 + ((e->ybot - y1) / 2);
		e->ytop = e->ytop + ((y1 - e->ytop) / 2);
	}
	else if (button == 2 || button == 5)
	{
		e->xbot = e->xbot - ((e->xtop - e->xbot) / 2);
		e->xtop = e->xtop + ((e->xtop - e->xbot) / 2);
		e->ybot = e->ybot - ((e->ytop - e->ybot) / 2);
		e->ytop = e->ytop + ((e->ytop - e->ybot) / 2);
	}
	expose_hook(e);
	return (1);
}
