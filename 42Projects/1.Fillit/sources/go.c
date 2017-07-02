/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blo <blo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 09:22:34 by blo               #+#    #+#             */
/*   Updated: 2016/11/29 17:13:05 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	alpha_tab(char ***tab, int ntetris)
{
	int bloc;
	int line;
	int kase;
	int letter;

	letter = 65;
	bloc = 0;
	while (bloc < ntetris)
	{
		line = 0;
		while (line < 4)
		{
			kase = 0;
			while (kase < 4)
			{
				if (tab[bloc][line][kase] == '#')
					tab[bloc][line][kase] = letter;
				kase++;
			}
			line++;
		}
		letter++;
		bloc++;
	}
}

void	map_to_tab(char *buff, char ***tab)
{
	int i;
	int bloc;
	int line;
	int kase;

	i = 0;
	bloc = 0;
	while (buff[i] != '\0')
	{
		line = -1;
		while (++line < 4)
		{
			kase = -1;
			while (++kase < 4)
			{
				tab[bloc][line][kase] = buff[i];
				i++;
			}
			i++;
		}
		if (buff[i] != '\0')
			i++;
		bloc++;
	}
}

char	***tab_map(char *buff)
{
	int		i;
	int		o;
	char	***tab;

	tab = (char ***)malloc(sizeof(char **) * tetrislen(buff));
	i = 0;
	while (i < tetrislen(buff))
	{
		tab[i] = (char **)malloc(sizeof(char *) * 4);
		o = 0;
		while (o < 4)
		{
			tab[i][o] = (char *)malloc(sizeof(char) * 4);
			o++;
		}
		i++;
	}
	map_to_tab(buff, tab);
	alpha_tab(tab, tetrislen(buff));
	return (tab);
}

int		go(char *argv)
{
	char	buff[BUFF_SIZE + 1];
	int		fd;
	int		ride;

	fd = open(argv, O_RDONLY);
	ride = read(fd, buff, BUFF_SIZE);
	if (ride < 20)
		return (write(1, "error\n", 6));
	buff[ride] = '\0';
	close(fd);
	if (check(buff) == 0)
		write(1, "error\n", 6);
	else
		resolution(tab_map(buff), tetrislen(buff));
	return (0);
}
