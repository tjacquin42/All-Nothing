/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pawn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:09:15 by tjacquin          #+#    #+#             */
/*   Updated: 2017/03/15 20:40:51 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int		rook(char **str, int i, int a, int size)
{
	int savei = i; 
	if (i >= 0 && i <= size && a >= 0 && a <= size && str[i][a] != 'K')
	{
		while (i > 0 && str[i][a] != 'K')
			i--;
		while (i < (size - 1) && str[i][a] != 'K')
			i++;
		if (str[i][a] != 'K')
			i = savei;
		i = ((str[i][a] == 'K') ? (i) : (i = savei));
		while (a > 0 && str[i][a] != 'K')
			a--;
		while (a < size && str[i][a] != 'K')
			a++;
	}
	if (str[i][a] == 'K')
		success(str);
	return (0);
}

int		bishop(char **str, int i, int a, int size)
{
	int savea = a;
	int savei = i;
	if (i >= 0 && i <= size && a >= 0 && a <= size && str[i][a] != 'K')
	{
		while (i > 0 && a > 0 && str[i][a] != 'K')
		{
			i--;
			a--;
		}
		while (i < (size - 1) && a < size && str[i][a] != 'K')
		{
			i++;
			a++;
		}
		i = ((str[i][a] == 'K') ? (i) : (i = savei));
		a = ((str[i][a] == 'K') ? (a) : (a = savea));
		while (i > 0 && a < size && str[i][a] != 'K')
		{
			i--;
			a++;
		}
		while (i < (size - 1) && a > 0 && str[i][a] != 'K')
		{
			i++;
			a--;
		}
	}
	if (str[i][a] == 'K')
		success(str);
	return (0);
}

int		queen(char **str, int i, int a, int size)
{
	int ret;
	
	ret = rook(str, i, a, size);
	bishop(str, i, a, size);
	return (0);
}

int		pawn(char **str, int i, int a, int size)
{
	if (str[i - 1][a - 1] == 'K'
			&& (i - 1) >= 0 && (i - 1) <= size &&
			(a - 1) >= 0 && (a - 1) <= size)
			return (1);
	if (str[i - 1][a + 1] == 'K'
			&& (i - 1) >= 0 && (i - 1) <= size &&
			(a + 1) >= 0 && (a + 1) <= size)
			return (1);
	return (0);
}
