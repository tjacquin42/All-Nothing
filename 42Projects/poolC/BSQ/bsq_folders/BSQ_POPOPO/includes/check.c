/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 14:45:43 by blo               #+#    #+#             */
/*   Updated: 2016/02/11 18:25:47 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

size_t	ft_strlen(char *str)
{
	size_t	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	cross(char *tab, char tall, int x, int save, char *param)
{
	int carre;
	int mem;
	int suce;

	carre = tall;
	mem = carre;
	suce = carre;
	while (save >= 0 && suce > 0)
	{
		while (carre > 0)
		{
			tab[save] = param[2];
			carre--;
			save--;
		}
		save = save - x + mem;
		carre = mem;
		save--;
		suce--;
	}
	ft_putstr(tab);
//	free(tab);
//	free(param);
}

int	superior(int left, int up, int diag)
{
	int	sup;

	sup = left;
	if (sup > up)
		sup = up;
	if (sup > diag)
		sup = diag;
	return (sup + 1);
}

void	check(char *grille, int line, char *param)
{
	int o;
	int tall;
	int *tab;
	int save;
	int i;

	save = 0;
	tab = (int*)malloc(sizeof(int) * (line * line));
	o = 0;
	tall = 0;
	i = 0;
	while (grille[o] != '\0')
	{
		if (grille[o] == '\n')
			o++;
		if (o < line && grille[o] != param[1])
			tab[i] = 1;
		else if (grille[o - 1] == '\n' && grille[o] != param[1])
			tab[i] = 1;
		else if (grille[o] == param[1])
			tab[i] = 0;
		else if (grille[o] == param[0])
			tab[i] = superior(tab[i - 1], tab[i - line], tab[i - line - 1]);
		if (tall < tab[i])
		{
			tall = tab[i];
			save = o;
		}
		i++;
		o++;
	}
//	free(tab);
	cross(grille, tall, line, save, param);
}

int	main(int argc, char **argv)
{
	char	buf[BUFF_SIZE + 1];
	char	*map;
	char	*tmp;
	int	fd;
	int	k;
	int	ret;

	k = 0;
	if (argc != 2)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	tmp = NULL;
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
	check(map, fd, tmp);
	return (0);
}
