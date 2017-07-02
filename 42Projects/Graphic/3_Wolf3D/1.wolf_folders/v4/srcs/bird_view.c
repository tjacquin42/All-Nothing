/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bird_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:23:57 by tjacquin          #+#    #+#             */
/*   Updated: 2017/05/23 15:38:43 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"


void		fov3(t_wo *s)
{
	int x;
	int y;

	s->color = 1900000;
	x = s->mv_x + (s->size_box / 4);
	y = s->mv_y + (s->size_box / 4);
	while (y < s->mv_y + 100)
	{
		while (x < s->mv_x + 100)
		{
			*(unsigned *)(s->gda + (y * s->szl + (x * s->bpx / 8))) = s->color;
			x = x + 1;
			y = y + s->rot_y;
		}
		y += 1;
	}
}

void		fov2(t_wo *s)
{
	int x;
	int y;

	s->color = 1900000;
	x = s->mv_x + (s->size_box / 4);
	y = s->mv_y + (s->size_box / 4);
	while (y < s->mv_y + 100)
	{
		while (x < s->mv_x + 100)
		{
			*(unsigned *)(s->gda + (y * s->szl + (x * s->bpx / 8))) = s->color;
			x = x + 1;
			y = y - 1 + s->rot_y;
		}
		y += 1;
	}
}

void		fov(t_wo *s)
{
	int x;
	int y;

	s->color = 1900000;
	x = s->mv_x + (s->size_box / 4);
	y = s->mv_y + (s->size_box / 4);
	while (y < s->mv_y + 100)
	{
		while (x < s->mv_x + 100)
		{
			*(unsigned *)(s->gda + (y * s->szl + (x * s->bpx / 8))) = s->color;
			x = x + 1;
			y = y + 1 + s->rot_y;
		}
		y += 1;
	}
}

void		player(t_wo *s)
{
	s->color = 1999000;
	int a;
	int b;

	a = 0;
	b = 0;
	s->ply_x = s->mv_x;
	s->ply_y = s->mv_y;
	while (a < (s->size_box / 2))
	{
		while (b < (s->size_box / 2))
		{
			*(unsigned *)(s->gda + (s->ply_y * s->szl + (s->ply_x++ * s->bpx / 8))) = s->color;
			b++;
		}
		a++;
		b = 0;
		s->ply_x = s->bird->x + s->mv_x;
		s->ply_y += 1;
	}
	fov(s);
	fov2(s);
	fov3(s);
}

void		case_1(t_wo *stk, t_brd *bird)
{
	stk->color = 16777215;
	while (bird->y < stk->size_box)
		*(unsigned *)(stk->gda + (bird->y++ + bird->dec_y) * stk->szl +
				((bird->x + bird->dec_x) * stk->bpx / 8)) = stk->color;
	while (bird->x < stk->size_box)
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
	while (bird->y < stk->size_box && stk->map[bird->i][bird->j - 1] != '1')
		*(unsigned *)(stk->gda + (bird->y++ + bird->dec_y) *
				stk->szl + ((bird->x + bird->dec_x) *
					stk->bpx / 8)) = stk->color;
	while (bird->x < stk->size_box && stk->map[bird->i - 1][bird->j] != '1')
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

void		map_trace(t_wo *s)
{
	while (s->bird->i < s->size_map)
	{
		while (s->bird->j < s->size_map)
		{
			if (s->map[s->bird->i][s->bird->j] == '1')
			{
				case_1(s, s->bird);
			}
			else if (s->map[s->bird->i][s->bird->j] == '0')
			{
				case_0(s, s->bird);
				player(s);
			}
			s->bird->j++;
			s->bird->dec_x += s->size_box;
		}
		s->bird->i++;
		s->bird->j = 0;
		s->bird->dec_x = 0;
		s->bird->dec_y += s->size_box;
	}
	s->bird->dec_y = 0;
	s->bird->i = 0;
}
