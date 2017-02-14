/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:46:00 by tjacquin          #+#    #+#             */
/*   Updated: 2016/06/12 21:19:28 by blo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	delete_tetrisinc(char **finalmap, int ascii, int lenreso)
{
	int line;
	int kase;

	line = 0;
	while (line < lenreso)
	{
		kase = 0;
		while (kase < lenreso)
		{
			if (finalmap[line][kase] == ascii)
				finalmap[line][kase] = '.';
			kase++;
		}
		line++;
	}
}

int		origin_line(char **tetrisinc)
{
	int line;
	int kase;

	line = 0;
	while (line < 4)
	{
		kase = 0;
		while (kase < 4)
		{
			if (tetrisinc[line][kase] != '.')
				return (line);
			kase++;
		}
		line++;
	}
	return (0);
}

int		origin_kase(char **tetrisinc)
{
	int line;
	int kase;

	line = 0;
	while (line < 4)
	{
		kase = 0;
		while (kase < 4)
		{
			if (tetrisinc[line][kase] != '.')
				return (kase);
			kase++;
		}
		line++;
	}
	return (0);
}

int		addtetrisinc(char **finalmap, int fline, int fkase, char **tetrisinc)
{
	int originline;
	int originkase;
	int line;
	int kase;

	originline = origin_line(tetrisinc);
	originkase = origin_kase(tetrisinc);
	line = -1;
	while (++line < 4)
	{
		kase = -1;
		while (++kase < 4)
		{
			if (tetrisinc[line][kase] != '.')
			{
				if (Y >= LENRESO || X >= LENRESO || finalmap[Y][X] != '.')
				{
					delete_tetrisinc(finalmap, asciitetris(tetrisinc), LENRESO);
					return (0);
				}
				finalmap[Y][X] = tetrisinc[line][kase];
			}
		}
	}
	return (1);
}
