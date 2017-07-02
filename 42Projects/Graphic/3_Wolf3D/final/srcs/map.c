/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:44:53 by tjacquin          #+#    #+#             */
/*   Updated: 2017/06/12 18:22:41 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	init_map_2(t_all *truc, int x, int y, int i)
{
	int		j;

	while (++i < x)
	{
		j = -1;
		while (++j < y)
		{
			if (i == 0)
				truc->map[i][j] = 15;
			else if (i == x - 1)
				truc->map[i][j] = 16;
			else if (j == y - 1)
				truc->map[i][j] = 17;
			else if (j == 0)
				truc->map[i][j] = 18;
			else
				truc->map[i][j] = (int)(rand() % 8 + 3);
			if (truc->map[i][j] >= 3 + truc->dens && truc->map[i][j] <= 10)
				truc->map[i][j] = 0;
		}
	}
}

void	init_map(t_all *truc, int x, int y)
{
	int		i;

	srand(time(NULL));
	i = 0;
	if ((truc->map = (int**)malloc(sizeof(int*) * x)) == 0)
		return ;
	while (i < x)
		if ((truc->map[i++] = (int*)malloc(sizeof(int) * y)) == 0)
			return ;
	i = -1;
	init_map_2(truc, x, y, i);
	truc->map[(int)(x / 2)][(int)(y / 2)] = 0;
	truc->player_pos_x = (int)(x / 2);
	truc->player_pos_y = (int)(y / 2);
}
