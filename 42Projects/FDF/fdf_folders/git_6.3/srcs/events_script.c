/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_script.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:37:19 by ghubert           #+#    #+#             */
/*   Updated: 2017/02/07 17:37:15 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float				d_r(float deg)
{
	float i;

	i = pi * deg / 180;
	return (i);
}

static void			print_img(fdf_t *stk)
{
	mlx_destroy_image(stk->mlx, stk->img);
	stk->img = mlx_new_image(stk->mlx, 1000, 1000);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	map_trace(stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
}

static void			img_rot(int keycode, fdf_t *stk)
{
	int i;

	i = 5;
	if (keycode == 53)
	{
		ft_memdel((void **)stk->mlx);
		ft_memdel((void **)stk->win);
		ft_memdel((void **)&stk);
		exit (0);
	}
	stk->rx = ((keycode == 91) ? (stk->rx += i) : (stk->rx));
	stk->rx = ((keycode == 84) ? (stk->rx -= i) : (stk->rx));
	stk->ry = ((keycode == 88) ? (stk->ry += i) : (stk->ry));
	stk->ry = ((keycode == 86) ? (stk->ry -= i) : (stk->ry));
	stk->rz = ((keycode == 92) ? (stk->rz += i) : (stk->rz));
	stk->rz = ((keycode == 89) ? (stk->rz -= i) : (stk->rz));
	stk->decal_x = ((keycode == 124) ? (stk->decal_x += 20) : (stk->decal_x));
	stk->decal_x = ((keycode == 123) ? (stk->decal_x -= 20) : (stk->decal_x));
	stk->decal_y = ((keycode == 125) ? (stk->decal_y += 20) : (stk->decal_y));
	stk->decal_y = ((keycode == 126) ? (stk->decal_y -= 20) : (stk->decal_y));
	print_img(stk);
}

int				img_gen(int keycode, fdf_t *stk)
{
	//map_trace(stk);
	//ft_putnbr(keycode);
	//ft_putchar(' ');
	if (keycode != 0)
		img_rot(keycode, stk);
	mlx_key_hook(stk->win, img_gen, stk);
	mlx_loop(stk->mlx);
	return (0);
}
