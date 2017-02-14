/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 14:45:43 by blo               #+#    #+#             */
/*   Updated: 2016/02/18 03:15:33 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

int		getparam(char *tmp)
{
	int		i;
	int		o;
	char	*line;

	i = 0;
	o = 0;
	if (ft_strlen(tmp) == 0)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	while (tmp[i] != '\n')
		i++;
	i = i - 3;
	line = (char *)malloc(sizeof(char) * i);
	while (i != o)
	{
		line[o] = tmp[o];
		o++;
	}
	return (ft_atoi(line));
}

int		bis(char *map, char *tmp, int fd, int k)
{
	fd = getparam(tmp);
	if (fd == 0)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	tmp = ft_strsub(tmp, k - 3, k);
	k = 0;
	if (verif(fd, map, tmp, k) == 0)
		return (0);
	check(map, fd, tmp, k);
	return (0);
}

int		okgo(int k, char *tmp, int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*map;
	int		ret;

	ret = read(fd, buf, BUFF_SIZE);
	if (ret < 4)
	{
		write(2, "map error\n", 10);
		return (0);
	}
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
	bis(map, tmp, fd, k);
	return (0);
}

int		main(int argc, char **argv)
{
	int		k;
	char	*tmp;
	int		fd;
	int		i;

	i = 2;
	k = 0;
	tmp = NULL;
	fd = 0;
	if (argc < 2)
		standinput(fd, tmp, k);
	if (argc >= 2)
	{
		while (i <= argc)
		{
			fd = open(argv[i - 1], O_RDONLY);
			okgo(k, tmp, fd);
			i++;
		}
	}
	return (0);
}
