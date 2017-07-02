/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 18:29:01 by tjacquin          #+#    #+#             */
/*   Updated: 2017/05/23 03:50:49 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void		print(t_wo *stk)
{/*
	mlx_destroy_image(stk->mlx, stk->img);
	stk->img = mlx_new_image(stk->mlx, stk->swin, stk->swin);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);*/
	map_trace(stk);/*
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);*/
}

int			event(int keycode, t_wo *stk)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 126)
		stk->mv_y -= 10;
	if (keycode == 125)
		stk->mv_y += 10;
	if (keycode == 124)
		stk->mv_x += 10;
	if (keycode == 123)
		stk->mv_x -= 10;
	//ft_putnbr(stk->co);
	//ft_putstr(" ");
	print(stk);
	return (0);
}
