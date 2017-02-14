/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:47:44 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/18 03:23:34 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		gettoparam(char *tmp)
{
	int		i;
	int		o;
	char	*line;

	i = 0;
	o = 0;
	while (tmp[i] != '\n')
	{
		i++;
	}
	i = i - 3;
	line = (char *)malloc(sizeof(char) * i);
	while (i != o)
	{
		line[o] = tmp[o];
		o++;
	}
	return (ft_atoi(line));
}

int		verify(int fd, char *gr, char *par, int i)
{
	int len;
	int lines;

	i = 0;
	len = 0;
	lines = 0;
	if (verifpar(par) == 0)
		return (0);
	while (gr[i] != '\0')
	{
		if (len <= fd && ((gr[i] == par[0]) || (gr[i] == par[1])))
			len++;
		else if (gr[i] == '\n' && len == fd)
		{
			len = 0;
			lines++;
		}
		i++;
	}
	if (lines != fd || i != (fd * fd + fd))
	{
		write(2, "map error\n", 10);
		return (0);
	}
	return (1);
}

int		bisu(char *map, char *tmp, int fd, int k)
{
	fd = gettoparam(tmp);
	if (fd == 0)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	tmp = ft_strsub(tmp, k - 3, k);
	k = 0;
	if (verify(fd, map, tmp, k) == 0)
		return (0);
	check(map, fd, tmp, k);
	return (0);
}

int		standinput(int fd, char *tmp, int k)
{
	char	buf[BUFF_SIZE + 1];
	char	*map;
	int		ret;

	ret = read(0, buf, BUFF_SIZE);
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
		ret = read(0, buf, BUFF_SIZE);
	}
	while (tmp[k] != '\n')
		k++;
	map = ft_strsub(tmp, k + 1, (ft_strlen(tmp) - k + 1));
	bisu(map, tmp, fd, k);
	return (0);
}
