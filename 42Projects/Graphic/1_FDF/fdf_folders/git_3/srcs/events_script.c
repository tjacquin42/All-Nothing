/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_script.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:37:19 by ghubert           #+#    #+#             */
/*   Updated: 2017/01/30 20:00:36 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

fdf_t				*print_img(fdf_t *stk)
{
	if (stk->img)
		mlx_destroy_image(stk->mlx, stk->img);
	stk->img = mlx_new_image(stk->mlx, 1000, 1000);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, stk->plx, stk->ply);
	return (stk);
}

static fdf_t		*img_rot(int keycode, fdf_t *stk)
{
	if (keycode == 126)
		stk = rot_server(ROTX, 10, stk);
	else if (keycode == 125)
		stk = rot_server(ROTX, -10, stk);
	else if (keycode == 123)
		stk = rot_server(ROTZ, -10, stk);
	else if (keycode == 124)
		stk = rot_server(ROTZ, 10, stk);
	ft_putnbr(keycode);
	ft_putchar('\n');
	stk = print_img(stk);
	return (stk);
}

int				img_gen(int keycode, fdf_t *stk)
{
	if (keycode == 0)
		stk = print_img(stk);
	if (keycode == 126)
		stk = img_rot(keycode, stk);

	mlx_key_hook(stk->win, img_gen, stk);
	mlx_loop(stk->mlx);
	return (0);
}
