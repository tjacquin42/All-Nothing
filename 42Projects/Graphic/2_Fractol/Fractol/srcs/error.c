/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:53:29 by tjacquin          #+#    #+#             */
/*   Updated: 2017/04/11 15:25:18 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		usage_error(void)
{
	ft_putstr("Usage : ./fractol [fractal type]\n\
	\n\
	kind of fractals available:\n\
				[B]   ->   Burning Bird\n\
				[C]   ->   Cross\n\
				[Jo]  ->   Julio\n\
				[Ju]  ->   Julia\n\
				[M]   ->   Mandelbrot\n\
				[N]   ->   Nintendo\n\
				[S]   ->   Burning Ship\n\
				[T]   ->   Tricorn\n");
	exit(1);
}
