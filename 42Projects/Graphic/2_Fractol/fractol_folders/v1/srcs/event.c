/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 02:28:37 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/23 17:08:07 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void		re_print(t_ol *stk)
{
	mlx_destroy_image(stk->mlx, stk->img);
	stk->img = mlx_new_image(stk->mlx, stk->swinx, stk->swiny);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	find_type(stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
}

int			event(int code, t_ol *stk)
{
	ft_putstr(" ");
	ft_putnbr(code);
	ft_putstr("  ");
	if (code == 53)
		free_exit(stk);
	stk->color = ((code == 47) ? (stk->color += 1) : (stk->color));
	stk->color = ((code == 43) ? (stk->color -= 1) : (stk->color));

	stk->decx = ((code == 124) ? (stk->decx += 10) : (stk->decx));
	stk->decx = ((code == 123) ? (stk->decx -= 10) : (stk->decx));
	stk->decy = ((code == 125) ? (stk->decy += 10) : (stk->decy));
	stk->decy = ((code == 126) ? (stk->decy -= 10) : (stk->decy));
	
	re_print(stk);
	return (0);
}
