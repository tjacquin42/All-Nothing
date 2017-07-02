/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchtall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 23:14:09 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/14 23:26:47 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		searchtall(char *grille, int *tab)
{
	int o;
	int i;
	int tall;
	int save;

	o = 0;
	i = 0;
	tall = 0;
	save = 0;
	while (grille[o] != '\0')
	{
		if (grille[o] == '\n')
			o++;
		else if (tall < tab[i])
		{
			tall = tab[i];
			save = o;
		}
		i++;
		o++;
	}
	free(tab);
	return (tall);
}
