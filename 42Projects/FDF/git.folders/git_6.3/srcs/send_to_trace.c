/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_trace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:55:58 by ghubert           #+#    #+#             */
/*   Updated: 2017/02/07 17:25:44 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		matricial(fdf_t *stk, int x, int y, int z, int i)
{
	float xp;
	float yp;
	float zp;

	stk->x_p[i] = x;
	stk->y_p[i] = cos(d_r(stk->rx)) * y - sin(d_r(stk->rx)) * z;
	stk->z_p[i] = sin(d_r(stk->rx)) * y + cos(d_r(stk->rx)) * z;
	xp = cos(d_r(stk->ry)) * stk->x_p[i] + sin(d_r(stk->ry)) * stk->z_p[i];
	yp = stk->y_p[i];
	zp = -(sin(d_r(stk->ry))) * stk->x_p[i] + cos(d_r(stk->ry)) * stk->z_p[i];
	stk->x_p[i] = cos(d_r(stk->rz)) * xp - sin(d_r(stk->rz)) * yp;
	stk->y_p[i] = sin(d_r(stk->rz)) * xp + cos(d_r(stk->rz)) * yp;
	stk->z_p[i] = zp;
}

void		stock_create(fdf_t *stk)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	if (!(stk->x_p = (float *)malloc(sizeof(float) * (stk->xmax * stk->ymax))))
		return ;
	if (!(stk->y_p = (float *)malloc(sizeof(float) * (stk->xmax * stk->ymax))))
		return ;
	if (!(stk->z_p = (float *)malloc(sizeof(float) * (stk->xmax * stk->ymax))))
		return ;
	while (y < (stk->ymax - 1))
	{
		x = 0;
		while (x < (stk->xmax - 1))
		{
			matricial(stk, (x + 1), (y + 1), stk->map[y][x], i++);
			x++;
		}
		y++;
	}
	//ft_putchar('\n');
}

void		trace_vertical(fdf_t *stk)
{
	int x;
	int y;
	int i;
	int point; // POINT

	i = 0;
	y = 1;
	point = get_center(stk); // MAP AT THE CENTER
	while (y++ < (stk->ymax - 1))
	{
		x = 1;
		while (x++ < stk->xmax)
		{
			stk->x1 = stk->x_p[i] * 20 + point + stk->decal_x;
			stk->x2 = stk->x_p[i + (stk->xmax - 1)] * 20 + point + stk->decal_x;
			stk->y1 = stk->y_p[i] * 20 + point + stk->decal_y;
			stk->y2 = stk->y_p[i++ + (stk->xmax - 1)] * 20 + point + stk->decal_y;
			segment_tracer(stk);
		}
	}
}

void		trace_horizontal(fdf_t *stk)
{
	int x;
	int y;
	int i;
	int point; //POINT

	i = 0;
	y = 1;
	point = get_center(stk); //MAP AT THE CENTER
	while (y++ < stk->ymax)
	{
		x = 1;
		while (x++ < (stk->xmax - 1))
		{
			stk->x1 = stk->x_p[i] * 20 + point + stk->decal_x;
			stk->x2 = stk->x_p[i + 1] * 20 + point + stk->decal_x;
			stk->y1 = stk->y_p[i] * 20 + point + stk->decal_y;
			stk->y2 = stk->y_p[i++ + 1] * 20 + point + stk->decal_y;
			segment_tracer(stk);
		}
		i++;
	}
}

void		map_trace(fdf_t *stk)
{
	if (stk->x_p)
		free(stk->x_p);
	if (stk->y_p)
		free(stk->y_p);
	if (stk->z_p)
		free(stk->z_p);
	stock_create(stk);
	trace_vertical(stk);
	trace_horizontal(stk);
}
