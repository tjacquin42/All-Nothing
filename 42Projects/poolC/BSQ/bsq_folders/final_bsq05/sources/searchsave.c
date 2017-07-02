/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchsave.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 23:04:48 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/14 23:16:40 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		searchsave(char *grille, int *tab)
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
	return (save);
}
