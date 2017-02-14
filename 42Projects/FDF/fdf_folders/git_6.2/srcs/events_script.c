/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_script.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:37:19 by ghubert           #+#    #+#             */
/*   Updated: 2017/02/07 15:53:40 by tjacquin         ###   ########.fr       */
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
	if (keycode == 53)
	{
		ft_memdel((void **)stk->mlx);
		ft_memdel((void **)stk->win);
		ft_memdel((void **)&stk);
		exit (0);
	}
	else if (keycode == 91)
		stk->rx += 5;
	else if (keycode == 84)
		stk->rx -= 5;
	else if (keycode == 88)
		stk->ry += 5;
	else if (keycode == 86)
		stk->ry -= 5;
	else if (keycode == 92)
		stk->rz += 5;
	else if (keycode == 89)
		stk->rz -= 5;
	else if (keycode == 124)
		stk->decal_x += 100;
	else if (keycode == 123)
		stk->decal_x -= 100;
	else if (keycode == 125)
		stk->decal_y += 100;
	else if (keycode == 126)
		stk->decal_y -= 100;
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
