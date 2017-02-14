/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:56:01 by ghubert           #+#    #+#             */
/*   Updated: 2017/01/30 19:51:43 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

fdf_t			*print_squares(int nb, int nb2, int x, int y, fdf_t *stk)
{
	while (x < nb)
	{
		if (x + 1 < nb && (x + 1) < nb2)
		{
			stk->x1 = (x + stk->x_p) * 5;
			stk->y1 = (y + stk->y_p) * 5;
			stk->x2 = (x + 1 + stk->x_p) * 5;
			stk->y2 = (stk->y1);
			segment_tracer(stk);
		}
		if (x < nb && x < nb2 && (y + 1) < stk->ln)
		{
			stk->x2 = stk->x1;
			stk->y2 = (y + 1 + stk->y_p) * 5;
			segment_tracer(stk);
		}
		if (x < nb && (x + 1) < nb2 && (y + 1) < stk->ln)
		{
			stk->x2 = (x + 1 + stk->x_p) * 5;
			segment_tracer(stk);
		}
		x++;
	}
	return (stk);
}
