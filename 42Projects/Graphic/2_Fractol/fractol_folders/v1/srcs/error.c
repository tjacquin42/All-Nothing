/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 01:26:37 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/23 17:43:14 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

 void		free_exit(t_ol *stk)
{
	if (stk)
		free(stk);
	exit(1);
}

void		argv_error(t_ol *stk)
{
	ft_putstr("\
	           Usage: ./fractol [fractal type]\n\
	           Fractal types availaible:\n\
	                                      [J]   ->   Julia \n\
	                                      [M]   ->   Mandelbrot\n\
	                                      [S]   ->   Square\n");
	free_exit(stk);
}

void		malloc_error(t_ol *stk)
{
	ft_putstr("malloc error\n");
	free_exit(stk);
}
