/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrislen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blo <blo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 09:25:47 by blo               #+#    #+#             */
/*   Updated: 2016/05/28 09:25:58 by blo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		strlentris(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\0')
		i++;
	return (i);
}

int		tetrislen(char *map)
{
	int nbrtetris;

	nbrtetris = (strlentris(map) + 1) / 21;
	return (nbrtetris);
}
