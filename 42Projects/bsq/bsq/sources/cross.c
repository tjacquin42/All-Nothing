/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 03:11:28 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/18 03:16:09 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	cross(char *grille, int x, char *param, int *tab)
{
	int carre;
	int mem;
	int socks;
	int save;
	int tall;

	save = searchsave(grille, tab);
	tall = searchtall(grille, tab);
	carre = tall;
	mem = carre;
	socks = carre;
	while (save >= 0 && socks > 0)
	{
		while (carre > 0)
		{
			grille[save] = param[2];
			carre--;
			save--;
		}
		save = save - x + mem;
		carre = mem;
		save--;
		socks--;
	}
	this_is_the_end(grille, param);
}
