/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 18:56:31 by tjacquin          #+#    #+#             */
/*   Updated: 2017/06/12 20:28:24 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	draw_vertical_3(t_all *truc, int x, int y1, int y2)
{
	if (truc->map[truc->mapx][truc->mapy] == 5)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_5;
	else if (truc->map[truc->mapx][truc->mapy] == 6)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_6;
	else if (truc->map[truc->mapx][truc->mapy] == 2)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_2;
	else
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = 0xFFFFFF;
}

void	draw_vertical_2(t_all *truc, int x, int y1, int y2)
{
	if (truc->map[truc->mapx][truc->mapy] == 4)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_4;
	else if (truc->map[truc->mapx][truc->mapy] == 15)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = WALL_1;
	else if (truc->map[truc->mapx][truc->mapy] == 16)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = WALL_2;
	else if (truc->map[truc->mapx][truc->mapy] == 17)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = WALL_3;
	else if (truc->map[truc->mapx][truc->mapy] == 18)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = WALL_4;
	else
		draw_vertical_3(truc, x, y1, y2);
}

void	draw_vertical(t_all *truc, int x)
{
	int		y1;
	int		y2;
	int		i;

	i = 0;
	y1 = truc->drawstart;
	y2 = truc->drawend;
	while (++i <= y1)
		*(unsigned *)(truc->data_addr + (i * truc->size) +
				(x * truc->bpx / 8)) = SKY;
	if (truc->map[truc->mapx][truc->mapy] == 1)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_1;
	else if (truc->map[truc->mapx][truc->mapy] == 3)
		while (++y1 <= y2)
			*(unsigned *)(truc->data_addr + (y1 * truc->size) +
					(x * truc->bpx / 8)) = COLOR_3;
	draw_vertical_2(truc, x, y1, y2);
	y2--;
	while (++y2 < H)
		*(unsigned *)(truc->data_addr + (y2 * truc->size) +
				(x * truc->bpx / 8)) = FLOOR;
}
