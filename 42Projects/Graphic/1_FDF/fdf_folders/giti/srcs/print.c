/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:00:38 by tjacquin          #+#    #+#             */
/*   Updated: 2017/01/26 19:09:44 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <math.h>
#define pi 3.1415926535
#define X_VALUE (((1 * x_place) + (0 * y_place) + (0 * z)) * (line + decal_x));
#define Y_VALUE (((0 * x_place) + (cos(deg_to_rad(30)) * y_place) + (-sin(deg_to_rad(30) * z))) * (line + decal_y));
#define Z_VALUE ((0 * x_place) + (sin(deg_to_rad(30)) * y_place) + (cos(deg_to_rad(30) * z)));

int		deg_to_rad(int deg)
{
	return ((deg * pi) / 180);
}


void	print_square(void *mlx, void *win)
{
	int x;
	int y;
	int z;
	int line;
	int num;
	int x_place;
	int y_place;
	int decal_x = 1;
	int decal_y = 5;

	num = 0;
	line = 1;
	z = 0;
	x_place = 10;
	y_place = 25;
	while (line <= 30)
	{
		num = 0;
		ft_putnbr(line);
		ft_putchar('\n');
		line++;
		x = X_VALUE;
		y = Y_VALUE;
		z = Z_VALUE;
		ft_putnbr(x);
		ft_putchar('\n');
		ft_putnbr(y);
		ft_putchar('\n');
		while (num < 15)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			num++;
			x = x + 15;
			y = y - 5;
		}
	}
}

int		main()
{
	void	*mlx;
	void	*win;
	//int		param1;
	//int		param2;
	int		num;
	
	mlx = mlx_init();
	//param1 = ft_atoi(argv[1]);
	//param2 = ft_atoi(argv[2]);
	//num = ft_atoi(argv[1]);
	win = mlx_new_window(mlx, 1000, 1000, "WIN");
	print_square(mlx, win);
	mlx_loop(mlx);
}
