/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:56:01 by ghubert           #+#    #+#             */
/*   Updated: 2017/02/01 18:58:15 by tjacquin         ###   ########.fr       */
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
	x = 0;
	y = 0;
	while ((y + 1)  < stk->ln)
	{
		while (x < nb)
		{
			if ((x + 1) < nb && (x + 1) < nb2)
			{
				stk->x1 = (x + 1) * 20;
				stk->y1 = (y + 1) * 20;
				stk->x2 = (x + 2) * 20;
				stk->y2 = (stk->y1);
/*
				ft_putchar('\n');
				ft_putnbr(stk->x1);
				ft_putstr("  <<-x1   y1->>  ");
				ft_putnbr(stk->y1);
				ft_putstr("\n");
				ft_putnbr(stk->x2);
				ft_putstr("  <<-x2   y2->>  ");
				ft_putnbr(stk->y2);
				ft_putchar('\n');
*/
				segment_pre_tracer(stk);
			}
			if (x < nb && x < nb2 && (y + 1) < stk->ln)
			{
				stk->x2 = stk->x1;
				stk->y2 = (y + 2) * 5;
				segment_pre_tracer(stk);
			}
			if (x < nb && (x + 1) < nb2 && y < stk->ln)
			{
				stk->x2 = (x + 1);
				segment_pre_tracer(stk);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (stk);
}
