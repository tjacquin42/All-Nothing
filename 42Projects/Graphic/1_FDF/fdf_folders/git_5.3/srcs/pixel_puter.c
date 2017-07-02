/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_puter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:46:25 by ghubert           #+#    #+#             */
/*   Updated: 2017/02/02 22:47:47 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static fdf_t	*revert_xy(fdf_t *truc)
{
	int		tmp;

	tmp = truc->x1;
	truc->x1 = truc->y1;
	truc->y1 = tmp;
	tmp = truc->x2;
	truc->x2 = truc->y2;
	truc->y2 = tmp;
	return (truc);
}

static void		up_down(fdf_t *truc, int dx, int dy, int e)
{
	ft_putnbr(truc->szl);
	ft_putstr(" ");
	ft_putnbr(truc->color);
	ft_putstr(" ");
	ft_putnbr(truc->x2);
	ft_putstr(" ");
	ft_putnbr(truc->y1);
	ft_putstr(" ");
	ft_putnbr(truc->y2);
	ft_putstr(" ");
	ft_putnbr(e);
	ft_putstr(" \n");
	truc = revert_xy(truc);
	e = truc->x2 - truc->x1;
	if (truc->x2 < truc->x1)
		e = truc->x1 - truc->x2;
	dx = e * 2;
	dy = (truc->y2 - truc->y1) * 2;
	if (dy < 0)
		dy = (truc->y1 - truc->y2) * 2;
	while (truc->x1 != truc->x2)
	{
		if (truc->x1 < 800 && truc->y1 < 1000 && truc->x1 > 0 && truc->y1 > 0)
		{
			*(unsigned *)(truc->gda + (truc->x1 * truc->szl) +
					(truc->y1 * truc->bpx / 8)) = truc->color;
			//mlx_pixel_put(truc->mlx, truc->win, truc->y1, truc->x1, 0x00FFFFF);
		}
		if (truc->x2 < truc->x1)
			truc->x1 = truc->x1 - 2;
		truc->x1 = truc->x1 + 1;
		if ((e = e - dy) <= 0)
		{
			if (truc->y1 > truc->y2)
				truc->y1 = truc->y1 - 2;
			truc->y1 = truc->y1 + 1;
			e = e + dx;
		}
	}
}

static void		left_right(fdf_t *truc, int dx, int dy, int e)
{
	e = truc->x2 - truc->x1;
	if (truc->x2 < truc->x1)
		e = truc->x1 - truc->x2;
	dx = e * 2;
	dy = (truc->y2 - truc->y1) * 2;
	if (dy < 0)
		dy = (truc->y1 - truc->y2) * 2;
	while (truc->x1 != truc->x2)
	{
		if (truc->x1 < 1000 && truc->y1 < 800 && truc->x1 > 0 && truc->y1 > 0)
		{
			*(unsigned *)(truc->gda + (truc->y1 * truc->szl) +
					(truc->x1 * truc->bpx / 8)) = truc->color;
			//mlx_pixel_put(truc->mlx, truc->win, truc->x1, truc->y1, 5555);
		}
		if (truc->x2 < truc->x1)
			truc->x1 = truc->x1 - 2;
		truc->x1 = truc->x1 + 1;
		if ((e = e - dy) <= 0)
		{
			if (truc->y1 > truc->y2)
				truc->y1 = truc->y1 - 2;
			truc->y1 = truc->y1 + 1;
			e = e + dx;
		}
	}
}

static void		loltest(fdf_t *truc, int dx, int dy, int e)
{
	e = truc->x2cp - truc->x1cp;
	if (truc->x2cp < truc->x1cp)
		e = truc->x1cp - truc->x2cp;
	dx = e * 2;
	dy = (truc->y2cp - truc->y1cp) * 2;
	if (dy < 0)
		dy = (truc->y1cp - truc->y2cp) * 2;
	while (truc->x1cp != truc->x2cp)
	{
		if (truc->x2cp < truc->x1cp)
			truc->x1cp = truc->x1cp - 2;
		truc->x1cp = truc->x1cp + 1;
		if ((e = e - dy) <= 0)
		{
			if (truc->y1cp > truc->y2cp)
				truc->y1cp = truc->y1cp - 2;
			truc->y1cp = truc->y1cp + 1;
			e = e + dx;
		}
	}
	if (truc->y1cp == truc->y2cp)
		left_right(truc, dx, dy, e);
	else
		up_down(truc, dx, dy, e);
}

void			segment_tracer(fdf_t *truc)
{
	int		dx;
	int		dy;
	int		e;

	truc->x1cp = truc->x1;
	truc->x2cp = truc->x2;
	truc->y1cp = truc->y1;
	truc->y2cp = truc->y2;
	e = 0;
	dx = 0;
	dy = 0;
	loltest(truc, dx, dy, e);
}
