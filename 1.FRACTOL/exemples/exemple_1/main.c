/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:33:55 by dchristo          #+#    #+#             */
/*   Updated: 2016/09/10 23:13:55 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	if (e->ftype == 1)
		mandelbrot(e);
	else if (e->ftype == 2)
		julia(e);
	else if (e->ftype == 3)
		newton(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF,
			ft_strjoin("UP / DOWN Iter (A/D) : ", ft_itoa(e->iter)));
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF, "Change Color (T)");
	mlx_string_put(e->mlx, e->win, 10, 50, 0xFFFFFF,
			"Move (fleche directionnelle)");
	mlx_string_put(e->mlx, e->win, 10, 70, 0xFFFFFF, "Mouse for Movement");
	return (1);
}

int		main(int ac, char **av)
{
	t_env e;

	init_env(&e, ac, av);
	mlx_key_hook(e.win, key_press, &e);
	mlx_mouse_hook(e.win, mouse, &e);
	mlx_hook(e.win, 6, 64, &mouse2, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (1);
}
