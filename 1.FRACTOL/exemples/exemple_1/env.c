/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 17:18:17 by dchristo          #+#    #+#             */
/*   Updated: 2016/09/10 23:38:52 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	error_arg(int n)
{
	if (n == 0)
		ft_putstr_fd("Aucun parametre trouver\n\n", 2);
	else if (n == 2)
		ft_putstr_fd("Trop de parametre envoye\n\n", 2);
	else
		ft_putstr_fd("Parametre incorrecte\n\n", 2);
	ft_putstr_fd("FRACT'OL : Relancer le programme avec l'un", 2);
	ft_putstr_fd(" des parametres suivants :\n", 2);
	ft_putstr_fd("M pour Mandelbrot\nJ pour Julia\nN pour Newton\n", 2);
	exit(EXIT_FAILURE);
}

int			frac_type(int ac, char **av)
{
	if (ac < 2)
		error_arg(0);
	if (ac > 2)
		error_arg(2);
	if (av[1][0] == 'M')
		return (1);
	else if (av[1][0] == 'J')
		return (2);
	else if (av[1][0] == 'N')
		return (3);
	error_arg(1);
	return (0);
}

void		init_sval(t_env *e)
{
	if (e->ftype == 1)
	{
		e->xbot = -2.5;
		e->xtop = 1;
		e->ybot = -1;
		e->ytop = 1;
	}
	else if (e->ftype == 2)
	{
		e->xbot = -2;
		e->xtop = 2;
		e->ybot = -2;
		e->ytop = 2;
	}
	else if (e->ftype == 3)
	{
		e->xbot = -4;
		e->xtop = 4;
		e->ybot = -4;
		e->ytop = 4;
		e->xs = e->img.width / 2;
	}
}

void		init_env(t_env *e, int ac, char **av)
{
	t_vec3	color;

	e->ftype = frac_type(ac, av);
	e->img.width = WIDTH;
	e->img.height = HEIGHT;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->img.width, e->img.height, "Fract'ol");
	e->img.img_ptr = mlx_new_image(e->mlx, e->img.width, e->img.height);
	e->img.img = (unsigned char *)mlx_get_data_addr(e->img.img_ptr, \
				&e->img.bpp, &e->img.sl, &e->img.endian);
	e->xs = 0;
	e->ys = 0;
	e->iter = 50;
	e->stop = 0;
	e->theme = 0;
	color = (t_vec3){0.0, 0.0, 0.0};
	e->color = color;
	init_sval(e);
	e->xoril = e->xbot;
	e->xorir = e->xtop;
}
