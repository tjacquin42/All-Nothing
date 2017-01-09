/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 23:50:32 by tjacquin          #+#    #+#             */
/*   Updated: 2016/12/14 00:10:34 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main()
{
	void	*lx;
	void	*win;
	int		x;
	int		y;
	int		a;
	int		b;

	lx = mlx_init();
	win = mlx_new_window(lx, 600, 1000, "First Use");
	y = 50;
	while (y < 750)
	{
		x = 50;
		while (x < 450)
		{
			if (y % 2 == 1 && x % 2 == 1 && (y / x  == 1) && x % 3 == 1)
				mlx_pixel_put(lx, win, x, y, 0x00FFFF);
			x++;
		}
		y++;
	}
/*	a = 15;
	while (a < 350)
	{
		x = 20;
		while (b < 750)
		{
			if (a % 2 == 0 && b % 2 == 1)
				mlx_pixel_put(lx, win, a, b, 0x00FFFFFF);
			x++;
		}
		y++;
	}*/
	mlx_loop(lx);
}
