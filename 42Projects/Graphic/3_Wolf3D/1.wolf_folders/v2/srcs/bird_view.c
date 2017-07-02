/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bird_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:23:57 by tjacquin          #+#    #+#             */
/*   Updated: 2017/05/10 19:22:35 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"
/*
void		player(t_wo *stk, t_brd *bird)
{
	stk->ply_x = bird->x;
	stk->ply_y = bird->y;
		while (bird->y < 20)
		*(unsigned *)(stk->gda + (bird->y++ * stk->szl + (bird->x * stk->bpx / 8))) = stk->color;
	while (bird->x < 20)
		*(unsigned *)(stk->gda + (bird->y * stk->szl + (bird->x++ * stk->bpx / 8))) = stk->color;
	while (bird->y > 0)
		*(unsigned *)(stk->gda + (bird->y-- + bird->dec_y) * stk->szl + ((bird->x + bird->dec_x) * stk->bpx / 8)) = stk->color;
	while (bird->x > 0)
		*(unsigned *)(stk->gda + (bird->y + bird->dec_y) * stk->szl + ((bird->x-- + bird->dec_x) * stk->bpx / 8)) = stk->color;

}
*/
void		case_1(t_wo *stk, t_brd *bird)
{
	stk->color = 16777215;
	while (bird->y < 20)
		*(unsigned *)(stk->gda + (bird->y++ + bird->dec_y) * stk->szl +
				((bird->x + bird->dec_x) * stk->bpx / 8)) = stk->color;
	while (bird->x < 20)
		*(unsigned *)(stk->gda + (bird->y + bird->dec_y) * stk->szl +
				((bird->x++ + bird->dec_x) *
				 stk->bpx / 8)) = stk->color;
	while (bird->y > 0)
		*(unsigned *)(stk->gda + (bird->y-- + bird->dec_y) *
				stk->szl + ((bird->x + bird->dec_x) *
					stk->bpx / 8)) = stk->color;
	while (bird->x > 0)
		*(unsigned *)(stk->gda + (bird->y + bird->dec_y) *
				stk->szl + ((bird->x-- + bird->dec_x) *
					stk->bpx / 8)) = stk->color;
}

void		case_0(t_wo *stk, t_brd *bird)
{
	stk->color = 20000;
	while (bird->y < 20 && stk->map[bird->i][bird->j - 1] != '1')
		*(unsigned *)(stk->gda + (bird->y++ + bird->dec_y) *
				stk->szl + ((bird->x + bird->dec_x) *
					stk->bpx / 8)) = stk->color;
	while (bird->x < 20 && stk->map[bird->i - 1][bird->j] != '1')
		*(unsigned *)(stk->gda + (bird->y + bird->dec_y) *
				stk->szl + ((bird->x++ + bird->dec_x) *
					stk->bpx / 8)) = stk->color;
	while (bird->y > 0)
		*(unsigned *)(stk->gda + (bird->y-- + bird->dec_y) *
				stk->szl + ((bird->x + bird->dec_x) *
					stk->bpx / 8)) = stk->color;
	while (bird->x > 0)
		*(unsigned *)(stk->gda + (bird->y + bird->dec_y) *
				stk->szl + ((bird->x-- + bird->dec_x) *
					stk->bpx / 8)) = stk->color;
}

void		map_trace(t_wo *stk, t_brd *bird)
{
	while (bird->i < 10)
	{
		while (bird->j < 10)
		{
			if (stk->map[bird->i][bird->j] == '1')
				case_1(stk, bird);
			else if (stk->map[bird->i][bird->j] == '0')
			{
				case_0(stk, bird);
				//player(stk, bird);
			}
			bird->j++;
			bird->dec_x += 20;
		}
		bird->i++;
		bird->j = 0;
		bird->dec_x = 0;
		bird->dec_y += 20;
	}
}

int			parce_map(t_wo *stk)
{
	t_brd *bird;

	if (!(bird = (t_brd*)malloc(sizeof(t_brd))))
		return (0);
	bird->i = 0;
	bird->j = 0;
	bird->dec_x = 0;
	bird->dec_y = 0;
	bird->x = 0;
	bird->y = 0;
	map_trace(stk, bird);
	return (0);
}
