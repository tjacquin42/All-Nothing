/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:47:44 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/17 20:10:00 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

int		standinput(int fd, char *tmp, int k)
{
	char	buf[BUFF_SIZE + 1];
	char	*map;
	int		ret;

	ret = read(0, buf, BUFF_SIZE);
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
	fd = ft_atoi(tmp);
	tmp = ft_strsub(tmp, k - 3, k);
	k = 0;
	if (verify(fd, map, tmp, k) == 0)
		return (0);
	check(map, fd, tmp, k);
	return (0);
}
