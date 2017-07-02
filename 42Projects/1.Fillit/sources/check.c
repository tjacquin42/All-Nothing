/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blo <blo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 09:21:14 by blo               #+#    #+#             */
/*   Updated: 2016/06/04 18:05:32 by blo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	checkform(char *map, int compt, int line)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		if (line == 4 && map[i] != '\n')
			return (0);
		else if (line == 4 && map[i++] == '\n')
			line = 0;
		while (compt < 4)
		{
			if (map[i] != '#' && map[i] != '.')
				return (0);
			i++;
			compt++;
		}
		if (map[i] != '\n' && compt == 4)
			return (0);
		else if (map[i] == '\n' && compt == 4)
			i++;
		compt = 0;
		line++;
	}
	return (1);
}

int	crosslinked(char *map, int i)
{
	int result;

	result = 0;
	if (map[i + 1] == '#' && i + 1 <= 20)
		result++;
	if (map[i - 1] == '#' && i - 1 >= 0)
		result++;
	if (map[i + 5] == '#' && i + 5 <= 20)
		result++;
	if (map[i - 5] == '#' && i - 5 >= 0)
		result++;
	return (result);
}

int	blocbybloc(char *map)
{
	int i;
	int linkcross;
	int other;
	int cross;

	i = 0;
	other = 0;
	linkcross = 0;
	cross = 0;
	while (map[i] != '\0' &&
			(map[i] == '.' || map[i] == '#' || map[i] == '\n'))
	{
		if (map[i] == '.' || map[i] == '\n')
			other++;
		else if (map[i] == '#')
		{
			linkcross = linkcross + crosslinked(map, i);
			cross++;
		}
		i++;
	}
	if (other == 16 && cross == 4 && (linkcross == 6 || linkcross == 8))
		return (1);
	else
		return (0);
}

int	checkbloc(char *map, int nbrtetri)
{
	int i;
	int bloc;

	i = 0;
	bloc = 0;
	while (nbrtetri > i)
	{
		if (blocbybloc(ft_strsub(map, bloc, 20)) == 0 &&
			(map[bloc - 1] == '\n' || map[bloc - 1] == '\0'))
		{
			return (0);
		}
		bloc += 21;
		i++;
	}
	return (1);
}

int	check(char *map)
{
	int nbrtetri;
	int compt;
	int line;

	line = 0;
	compt = 0;
	nbrtetri = tetrislen(map);
	if ((strlentris(map) + 1) % 21 == 0 && checkbloc(map, nbrtetri) == 1 &&
			checkform(map, compt, line) == 1)
		return (1);
	else
		return (0);
}
