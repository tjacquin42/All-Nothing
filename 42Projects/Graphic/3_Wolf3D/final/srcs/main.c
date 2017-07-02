/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:32:35 by tjacquin          #+#    #+#             */
/*   Updated: 2017/06/12 21:04:08 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	find_walls(t_all *truc)
{
	int x;

	x = 0;
	while (x < W)
	{
		ray_caster(truc, x);
		x++;
	}
	mlx_put_image_to_window(truc->mlx, truc->win, truc->img, 0, 0);
}

void	init_values(t_all *truc, char **av)
{
	int		x_y[2];

	x_y[0] = ft_atoi(av[1]);
	x_y[1] = ft_atoi(av[2]);
	if (x_y[0] < 5)
		x_y[0] = 5;
	if (x_y[1] < 5)
		x_y[1] = 5;
	if (x_y[0] > 1000)
		x_y[0] = 1000;
	if (x_y[1] > 1000)
		x_y[1] = 1000;
	truc->dirx = -1;
	truc->diry = 0;
	truc->planex = 0;
	truc->planey = (double)FOV / 100;
	truc->player_moving_up = 0;
	truc->player_moving_left = 0;
	truc->player_moving_down = 0;
	truc->player_moving_right = 0;
	truc->which = 1;
	init_map(truc, x_y[0], x_y[1]);
	find_walls(truc);
}

void	init_mlx(t_all *truc, char **av)
{
	if ((truc->dens = ft_atoi(av[3])) < 0)
		truc->dens = 0;
	if (truc->dens > 4)
		truc->dens = 4;
	truc->mlx = mlx_init();
	truc->win = mlx_new_window(truc->mlx, W, H, "Wolf3D");
	truc->img = mlx_new_image(truc->mlx, W, H);
	truc->data_addr = mlx_get_data_addr(truc->img, &truc->bpx,
			&truc->size, &truc->idgaf);
	truc->move_speed = 0.09;
	init_values(truc, av);
	mlx_do_key_autorepeatoff(truc->mlx);
	mlx_loop_hook(truc->mlx, loop_hook, truc);
	mlx_hook(truc->win, 2, 1L << 0, key_input, truc);
	mlx_hook(truc->win, 17, 1L << 0, exit_redcross, truc);
	mlx_key_hook(truc->win, key_input, truc);
	mlx_mouse_hook(truc->win, mouse_input, truc);
	mlx_loop(truc->mlx);
}

int		main(int ac, char **av)
{
	t_all	*truc;

	if (ac != 4)
	{
		ft_putstr("usage: ./wolf3d length(5-1000) width");
		ft_putstr("(5-1000) wall_density(0-4)" "\n");
		return (0);
	}
	if ((truc = (t_all*)malloc(sizeof(t_all))) == 0)
		return (0);
	system("afplay ./musics/kirby.mp3 &");
	init_mlx(truc, av);
	return (0);
}
