/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 00:49:56 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/23 18:11:24 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	find_type(t_ol *stk)
{
	int		i;

	i = 0;
	if (stk->type[i] == 'J' || stk->type[i] == 'j')
		return (julia(stk));
	else if (stk->type[i] == 'M' || stk->type[i] == 'm')
		return (mandel(stk));
	else if (stk->type[i] == 'S' || stk->type[i] == 's')
		return (square(stk));
	argv_error(stk);
}

void	init(t_ol *stk)
{
	stk->swinx = 1500;
	stk->swiny = 1000;
	stk->color = 1646846;
	stk->decx = 0;
	stk->decy = 0;
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, stk->swinx, stk->swiny, "Fract'ol");
	stk->img = mlx_new_image(stk->mlx, stk->swinx, stk->swiny);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	find_type(stk);
	mlx_hook(stk->win, 2, 3, event, stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);
}

int		main(int argc, char **argv)
{
	t_ol *stk;

	if (!(stk = (t_ol *) malloc(sizeof(t_ol))))
		malloc_error(stk);
	if (argc != 2 || ft_strlen(argv[1]) > 1)
		argv_error(stk);
	stk->type = argv[1];
	init(stk);
	return (0);
}
