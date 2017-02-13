/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 00:49:56 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/13 07:21:46 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		find_type(char *type)
{
	int		ret;
	char	*julia;
	char	*mandelbrot;
	//int		i;

	ret = -1;
	julia = (char *)malloc(sizeof(char) * 5);
	julia = "julia";
	mandelbrot = (char *) malloc(sizeof(char) * 10);
	mandelbrot = "mandelbrot";
	ft_strtolower(type);
	ft_putstr(type);
	ret = ((ft_strcmp(julia, type) == 0) ? JULIA : ret);
	ret = ((ft_strcmp(mandelbrot, type) == 0) ? MANDEL : ret);
	return (ret);
}

int		main(int argc, char **argv)
{
	t_ol *stk;

	if (!(stk = (t_ol *) malloc(sizeof(t_ol))))
		malloc_error(stk);
	if (argc != 2)
		argv_error(stk);
	init(find_type(argv[1]), stk);
	return (0);
}
