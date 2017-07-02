/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:56:01 by ghubert           #+#    #+#             */
/*   Updated: 2017/02/01 16:09:10 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			segment_pre_tracer(fdf_t *stk)
{
	if (stk->x_d == 0 && stk->y_d == 0 && stk->z_d == 0)
		segment_tracer(stk);
	if (stk->x_d != 0)
		stk = rot_server(ROTX, stk);
	if (stk->y_d != 0)
		stk = rot_server(ROTY, stk);
	if (stk->z_d != 0)
		stk = rot_server(ROTZ, stk);
	segment_tracer(stk);
}

fdf_t			*print_squares(int nb, int nb2, int x, int y, fdf_t *stk)
{
	while (x < nb)
	{
		if (x + 1 < nb && (x + 1) < nb2)
		{
			stk->x1 = (x) * 100;
			stk->y1 = (y) * 100;
			stk->x2 = (x + 1) * 100;
			stk->y2 = (stk->y1);
			segment_pre_tracer(stk);
		}
		if (x < nb && x < nb2 && (y + 1) < stk->ln)
		{
			stk->x2 = stk->x1;
			stk->y2 = (y + 1) * 5;
			segment_pre_tracer(stk);
		}
		if (x < nb && (x + 1) < nb2 && (y + 1) < stk->ln)
		{
			stk->x2 = (x + 1) * 5;
			segment_pre_tracer(stk);
		}
		x++;
	}
	return (stk);
}
