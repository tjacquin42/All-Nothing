/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:04:35 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/09 16:04:38 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_exit(void)
{
	exit(1);
}

void		malloc_error(void *thing)
{
	free(thing);
	ft_putstr_fd("malloc has been burst >_<\n", 2);
	fdf_exit();
}

void		map_error(void)
{
	ft_putstr_fd("Don't be stupid and put a valid map\n", 2);
	fdf_exit();
}

void		argv_error(int arg)
{
	if (arg == 2)
		ft_putstr("FDF can't do an orgy...\n");
	if (arg == 1)
		ft_putstr("FDF can't jacking off...\n");
	fdf_exit();
}
