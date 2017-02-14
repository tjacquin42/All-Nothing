/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:00:38 by tjacquin          #+#    #+#             */
/*   Updated: 2017/01/30 20:02:39 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/fdf.h"

#define X_VALUE (((1 * x_place) + (0 * y_place) + (0 * z)) * (line + decal_x));
#define Y_VALUE (((0 * x_place) + (cos(deg_to_rad(30)) * y_place) + (-sin(deg_to_rad(30) * z))) * (line + decal_y));
#define Z_VALUE ((0 * x_place) + (sin(deg_to_rad(30)) * y_place) + (cos(deg_to_rad(30) * z)));

int		deg_to_rad(int deg)
{
	return ((deg * pi) / 180);
}
/*
int		key_change(int a, int x)
{
	static int y = 0;
	if (a == 126)
	{
		y = y + x + 20;
	}
	if (a == 125)
		y = y + x - 20;
	ft_putnbr(a);
	ft_putchar('\n');
	return (y);
}*/

void	print_square(void *win, fdf_t *stk)
{
	int x;
	int y;
	int z;
	int line;
	int num;
	int decal_x = 1;
	int decal_y = 5;
	static int x_place = 10;
	static int y_place = 25;

	num = 0;
	line = 1;
	z = 0;
	x_place = mlx_key_hook(win, key_change, &x_place);
	while (line <= 30 && stk->map)
	{
		num = 0;
		line++;
		x = X_VALUE;
		y = Y_VALUE;
		z = Z_VALUE;
		while (num < 15)
		{
			mlx_pixel_put(stk->mlx, win, x, y, 0x0099999);
			mlx_pixel_put(stk->mlx, win, x_place, y_place, 0x00FFFFFF);
			num++;
			x = x + 15;
			y = y - 5;
		}
	}
}

void		get_map(fdf_t *stk)
{
	void	*mlx;
	void	*win;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "WIN");
	print_square(win, stk);
	//mlx_key_hook(win, key_change, stk);
	mlx_loop(mlx);
}
