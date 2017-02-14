/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:00:38 by tjacquin          #+#    #+#             */
/*   Updated: 2017/01/27 18:25:18 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <math.h>
#define pi		3.1415926535
#define X_VALUE	(((1 * x_place) + (0 * y_place) + (0 * z)) * (line + decal_x));
#define Y_VALUE	(((0 * x_place) + (cos(deg_to_rad(0)) * y_place) + (-sin(deg_to_rad(0) * z))) * (line + decal_y));
#define Z_VALUE	((0 * x_place) + (sin(deg_to_rad(0)) * y_place) + (cos(deg_to_rad(0) * z)));

#define PAS_X	x + 15
#define PAS_Y	y - 5
int		deg_to_rad(int deg)
{
	return ((deg * pi) / 180);
}


void	print_square(void *mlx, void *win, fdf_t stk)
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
	
	int i;

	i = 0;

	num = 0;
	line = 1;
	z = 0;
	x_place = 10;
	y_place = 25;
	while (stk.map[i])
	{

		num = 0;
		line++;
		x = X_VALUE;
		y = Y_VALUE;
		z = Z_VALUE;
		while (num < 10)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			num++;
			x = PAS_X;
			y = PAS_Y;
		}
		ft_putnbr(stk.map[i]);
		i++;
	}
}

void	get_map(fdf_t stk)
{
	void	*mlx;
	void	*win;
	int		num;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "WIN");
	print_square(mlx, win, stk);
	mlx_loop(mlx);
}
