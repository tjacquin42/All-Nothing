/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:45:49 by ghubert           #+#    #+#             */
/*   Updated: 2017/01/30 16:53:56 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"
#include <math.h>

static int			d_r(int deg)
{
	return((deg * pi) / 180);
}

static fdf_t		*rot_x(int d, fdf_t *stk)
{
	int		yp;
	int		zp;

	if (d != 0)
	{
		yp = (cos(d_r(d)) * (1 + stk->y_p)) - (sin(d_r(d)) * (1 + stk->z_p));
		zp = (sin(d_r(d)) * (1 + stk->y_p)) + (cos(d_r(d)) * (1 + stk->z_p));
		stk->y_p = yp - 1;
		stk->z_p = zp - 1;
	}
	return (stk);
}

static fdf_t		*rot_y(int d, fdf_t *stk)
{
	int		xp;
	int		zp;

	if (d != 0)
	{
		xp = (cos(d_r(d)) * (1 + stk->x_p)) + (sin(d_r(d)) * (1 + stk->z_p));
		zp = -(sin(d_r(d)) * (1 + stk->x_p)) + (cos(d_r(d)) * (1 + stk->z_p));
		stk->x_p = xp - 1;
		stk->z_p = zp - 1;
	}
	return (stk);
}

static fdf_t		*rot_z(int d, fdf_t *stk)
{
	int		xp;
	int		yp;

	if (d != 0)
	{
		xp = (cos(d_r(d)) * (1 + stk->x_p)) - (sin(d_r(d)) * (1 + stk->y_p));
		yp = (sin(d_r(d)) * (1 + stk->x_p)) + (cos(d_r(d)) * (1 + stk->y_p));
		stk->x_p = xp - 1;
		stk->y_p = yp - 1;
	}
	return (stk);
}

fdf_t				*rot_server(int rotaxis, int d, fdf_t *stk)
{
	if (rotaxis == ROTX)
		stk = rot_x(d, stk);
	else if (rotaxis == ROTY)
		stk = rot_y(d, stk);
	else if (rotaxis == ROTZ)
		stk = rot_z(d, stk);
	
	return (stk);
}
