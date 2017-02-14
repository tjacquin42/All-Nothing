/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:00:38 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/02 22:49:26 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <math.h>

#define pi 3.1415926535
#define X_VALUE (((1 * x_place) + (0 * y_place) + (0 * z)) * (line + decal_x));
#define Y_VALUE (((0 * x_place) + (cos(deg_to_rad(0)) * y_place) + (-sin(deg_to_rad(0) * z))) * (line + decal_y));
#define Z_VALUE ((0 * x_place) + (sin(deg_to_rad(30)) * y_place) + (cos(deg_to_rad(30) * z)));

int		deg_to_rad(int deg)
{
	return ((deg * pi) / 180);
}

int		key_change(int a)
{
	static int b = 0;

	if (a == 126)
		b++;
	ft_putnbr(b);
	return (0);
}

static void		left_right(int dx, int dy, void mlx, void win)
{
	int x1 = 40;
	int x2 = 40;
	int y1 = 20;
	int y2 = 10;
	int bpx = 32;
	int gda;
	int e;
	int szl = 4000;
	int	color = 0;

	e = x2 - x1;
	if (x2 < x1)
		e = x1 - x2;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	if (dy < 0)
		dy = (y1 - y2) * 2;
	while (x1 != x2)
	{
		if (x1 < 1000 && y1 < 800 && x1 > 0 && y1 > 0)
		{
			*(unsigned *)(gda + (y1 * szl) +
				(x1 * bpx / 8)) = color;
				mlx_pixel_put(mlx, win, x1, y1, 5555);
		}
		if (x2 < x1)
				x1 = x1 - 2;
		x1 = x1 + 1;
		if ((e = e - dy) <= 0)
		{
			if (y1 > y2)
				y1 = y1 - 2;
			y1 = y1 + 1;
			e = e + dx;
		}
	}
}

void	print_square(void *mlx, void *win)
{
	int		x;
	int		y;
	int		z;
	int		line;
	int		num;
	int		x_place;
	int		y_place;
	int		decal_x = 1;
	int		decal_y = 1;
	void	*img;
	char	*pix_img;
	int		bpp;
	int		s_line;
	int		ed;

	img = mlx_new_image(mlx, 1000, 1000);
	pix_img = mlx_get_data_addr(img, &bpp, &s_line, &ed);
	num = 0;
	line = 1;
	z = 0;
	x_place = 10;
	y_place = 10;
	left_right(x, y, mlx, win);
	/*
	while (line <= 30)
	{
		num = 0;
		line++;
		x = X_VALUE;
		y = Y_VALUE;
		z = Z_VALUE;
		while (num < 15)
		{
			//mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			num++;
			x = x + 10;
			y = y - 10;
		}
	}*/
	mlx_put_image_to_window(mlx, win, img, -50, -50);
	mlx_destroy_image(mlx, img);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		a;

	a = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "WIN");
	print_square(mlx, win);
	//mlx_key_hook(win, key_change, 0);
	mlx_loop(mlx);
}
