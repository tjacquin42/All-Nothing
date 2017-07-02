/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 18:29:01 by tjacquin          #+#    #+#             */
/*   Updated: 2017/05/10 19:23:38 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void		print(t_wo *stk)
{
	mlx_destroy_image(stk->mlx, stk->img);
	stk->img = mlx_new_image(stk->mlx, 1000, 1000);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	parce_map(stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
}

int			event(int keycode, t_wo *stk)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 26)
		stk->color += 10;
	print(stk);
	return (0);
}
