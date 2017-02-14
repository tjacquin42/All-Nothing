/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:52:57 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/02 19:40:02 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_fdf	*stk;
	t_map	*map;

	if (argc == 2)
	{
		if (!(stk = (t_fdf *)malloc(sizeof(t_fdf))))
			malloc_error();
		map = parse(argv[1], 
	}
	return (0);
}
