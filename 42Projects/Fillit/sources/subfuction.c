/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subfuction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blo <blo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 17:18:55 by blo               #+#    #+#             */
/*   Updated: 2016/06/12 21:05:09 by blo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		asciitetris(char **tetrisinc)
{
	int line;
	int kase;

	line = 0;
	while (line < 4)
	{
		kase = 0;
		while (kase < 4)
		{
			if (tetrisinc[line][kase] != '.' && tetrisinc[line][kase])
				return (tetrisinc[line][kase]);
			kase++;
		}
		line++;
	}
	return (0);
}

void	print_finalmap(char **finalmap, int lenreso)
{
	int line;
	int kase;

	line = 0;
	while (line < lenreso)
	{
		kase = 0;
		while (kase < lenreso)
		{
			write(1, &finalmap[line][kase], 1);
			kase++;
		}
		write(1, "\n", 1);
		line++;
	}
	exit(1);
}

void	ccleanmap(char **finalmap, int ascii, int lenreso)
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

char	**finalmap(int lenmap)
{
	char	**finalmap;
	int		line;
	int		kase;

	line = 0;
	finalmap = (char **)malloc(sizeof(char*) * lenmap);
	while (line < lenmap)
	{
		finalmap[line] = (char *)malloc(sizeof(char) * lenmap + 1);
		line++;
	}
	line = 0;
	while (line < lenmap)
	{
		kase = 0;
		while (kase < lenmap)
		{
			finalmap[line][kase] = '.';
			kase++;
		}
		finalmap[line][kase] = '\0';
		line++;
	}
	return (finalmap);
}
