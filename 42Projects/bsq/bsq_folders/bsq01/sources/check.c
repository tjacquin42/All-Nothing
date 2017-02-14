/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 14:45:43 by blo               #+#    #+#             */
/*   Updated: 2016/02/06 16:50:27 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

void	cross(char *tab, char tall, int x, int save)
{
	int carre;
	int mem;
	int suce;

	carre = tall - 48;
	mem = carre;
	suce = carre;
	while (save >= 0 && suce > 0)
	{
		while (carre > 0)
		{
			tab[save] = 'x';
			carre--;
			save--;
		}
		save = save - x + mem;
		carre = mem;
		save--;
		suce--;
	}
}

void	final(char *tab, char tall, int x, int o)
{
	int save;

	save = 0;
	while (tab[o] != tall)
		o++;
	save = o;
	o = 0;
	while ((x * x + x) != o)
	{
		if (tab[o] == '0')
			tab[o] = 'o';
		else if (tab[o] != '\n')
			tab[o] = '.';
		o++;
	}
	cross(tab, tall, x, save);
	ft_putstr(tab);
}

char	superior(char left, char up, char diag)
{
	char sup;

	sup = left;
	if (sup > up)
		sup = up;
	if (sup > diag)
		sup = diag;
	return (sup + 1);
}

void	check(char *tab, int x)
{
	int o;
	char tall;

	o = 0;
	tall = 0;
	while ((x * x + x) != o)
	{
		if (o < x && tab[o] != 'o')
			tab[o] = '1';
		else if ((tab[o] == '\n') && tab[o + 1] != 'o' && tab[o + 1] != '\0')
			tab[o + 1] = '1';
		else if (tab[o] == 'o')
			tab[o] = '0';
		else if (tab[o] == '.')
			tab[o] = superior(tab[o - 1], tab[o - x - 1], tab[o - x - 2]);
		if (tall < tab[o])
			tall = tab[o];
		o++;
	}
	o = 0;
	final(tab, tall, x, o);
}

int main(int argc, char **argv)
{
	char	buf[130];
	char	*map;
	int		fd;
	int		k = 0;
	int		ret;

	if (argc != 2)
	{
		ft_putstr("map error\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, 129);
	buf[ret] = '\0';
	while (buf[k] != '\n')
		k++;
	map = ft_strsub(buf, k + 1, (ft_strlen(buf) - k + 1));
	check(map, 10);
	return (0);
}
