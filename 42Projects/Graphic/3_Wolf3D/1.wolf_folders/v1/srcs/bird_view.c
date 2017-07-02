/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bird_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:23:57 by tjacquin          #+#    #+#             */
/*   Updated: 2017/05/10 17:35:18 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void		map_trace(t_wo *stk, t_brd *bird)
{
	while (bird->j < 10)
	{
		if (stk->map[bird->i][bird->j] == '1')
		{
			while (bird->y < 20)
				*(unsigned *)(stk->gda + (bird->y++ + bird->dec_y) * stk->szl + ((bird->x + bird->dec_x) * stk->bpx / 8)) = stk->color;
			while (bird->x < 20)
				*(unsigned *)(stk->gda + (bird->y + bird->dec_y) * stk->szl + ((bird->x++ + bird->dec_x) * stk->bpx / 8)) = stk->color;
			while (bird->y > 0)
				*(unsigned *)(stk->gda + (bird->y-- + bird->dec_y) * stk->szl + ((bird->x + bird->dec_x) * stk->bpx / 8)) = stk->color;
			while (bird->x > 0)
				*(unsigned *)(stk->gda + (bird->y + bird->dec_y) * stk->szl + ((bird->x-- + bird->dec_x) * stk->bpx / 8)) = stk->color;
		}
		bird->j++;
		bird->dec_x += 20;
	}
}

int			parce_map(t_wo *stk)
{
	t_brd *bird;

	if (!(bird = (t_brd*)malloc(sizeof(t_brd))))
		return (0);
	bird->i = 0;
	bird->dec_x = 0;
	bird->dec_y = 0;
	bird->x = 0;
	bird->y = 0;
	map_trace(stk, bird);
	return (0);
}
