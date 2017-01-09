/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 14:45:43 by blo               #+#    #+#             */
/*   Updated: 2016/02/15 00:22:07 by tjacquin         ###   ########.fr       */
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

void	check(char *grille, int line, char *param, int i)
{
	int o;
	int *tab;

	tab = (int*)malloc(sizeof(int) * (line * line));
	o = 0;
	while (grille[o] != '\0')
	{
		if (grille[o] == '\n')
			o++;
		if ((o < line && grille[o] != param[1]) || \
				(grille[o - 1] == '\n' && grille[o] != param[1]))
			tab[i] = 1;
		else if (grille[o] == param[1])
			tab[i] = 0;
		else if (grille[o] == param[0])
			tab[i] = superior(tab[i - 1], tab[i - line], tab[i - line - 1]);
		i++;
		o++;
	}
	cross(grille, line, param, tab);
}
/*
void	verif(int fd, char *gr)
{
	int i;
	int len;
	int lines;

	i = 0;
	len = fd;
	lines = 1;
	while (gri[len] != '\0')
	{
		if (len >= 1 && \
				((gr[i] == par[1]) || (gr[i] == par[2]) || (gr[i] == par[3])))
		{
			len--;
		}
		else if (grille[i] == '\n')
		{
			len = 1;
			lines++;
		}
		i++;
	}
	if (lines == fd && )
}
*/
void	okgo(int k, char *tmp, int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*map;
	int		ret;
	int		i;

	i = 0;
	ret = read(fd, buf, BUFF_SIZE);
	while (ret)
	{
		buf[ret] = '\0';
		if (tmp)
			tmp = ft_strjoin(tmp, buf);
		else
			tmp = ft_strdup(buf);
		ret = read(fd, buf, BUFF_SIZE);
	}
	close(fd);
	while (tmp[k] != '\n')
		k++;
	map = ft_strsub(tmp, k + 1, (ft_strlen(tmp) - k + 1));
	fd = ft_atoi(tmp);
	tmp = ft_strsub(tmp, k - 3, k);
	check(map, fd, tmp, i);
}

int		main(int argc, char **argv)
{
	int		k;
	char	*tmp;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	k = 0;
	tmp = NULL;
	if (argc != 2)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	else
		okgo(k, tmp, fd);
	return (0);
}
