/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchtall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 23:14:09 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/16 18:27:28 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		searchtall(char *grille, int *tab)
{
	int o;
	int i;
	int tall;

	o = 0;
	i = 0;
	tall = 0;
	while (grille[o] != '\0')
	{
		if (grille[o] == '\n')
			o++;
		else if (tall < tab[i])
		{
			tall = tab[i];
		}
		i++;
		o++;
	}
	free(tab);
	return (tall);
}
