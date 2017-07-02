/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blo <blo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 14:41:58 by blo               #+#    #+#             */
/*   Updated: 2016/06/12 21:19:52 by blo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		sizemap(char **final)
{
	int i;

	i = 0;
	while (final[0][i] != '\0')
		i++;
	return (i);
}

void	process(char ***tab, char **finalmap, int nbtetris, int tetrisinc)
{
	int	line;
	int	kase;

	line = 0;
	while (line < LENRESO)
	{
		kase = 0;
		while (kase < LENRESO)
		{
			if (addtetrisinc(finalmap, line, kase, tab[tetrisinc]))
			{
				if (tetrisinc + 1 != nbtetris)
					process(tab, finalmap, nbtetris, tetrisinc + 1);
				else
					print_finalmap(finalmap, LENRESO);
				ccleanmap(finalmap, asciitetris(tab[tetrisinc]), LENRESO);
			}
			kase++;
		}
		line++;
	}
}

int		lowestmap(int nbtetris)
{
	int i;

	i = 2;
	while (i * i < nbtetris * 4)
		i++;
	return (i);
}

void	resolution(char ***tab, int nbtetris)
{
	int lenmap;

	lenmap = lowestmap(nbtetris);
	while (lenmap)
	{
		process(tab, finalmap(lenmap), nbtetris, 0);
		lenmap++;
	}
}
