/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:00:04 by tjacquin          #+#    #+#             */
/*   Updated: 2017/01/20 19:36:41 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		num_n(char *buff, int fetich)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (n != fetich)
	{
		i++;
		if (buff[i] == '\0')
			return (0);
		if (buff[i] == '\n')
		{
			n++;
			i++;
		}
	}
	return (i);
}

int		until_n(char *buff, int fetich)
{
	int i;
	int len;

	i = num_n(buff, fetich);
	len = 0;
	while (buff[i] != '\n')
	{
		i++;
		len++;
	}
	return (len);
}

int		get_line(char *buff, char **line, int fetich)
{
	int i;
	int n;
	int x;

	i = num_n(buff, fetich);
	x = 0;
	while (buff[i] != '\0')
	{
		while (buff[i] != '\n')
		{
			ft_putchar(buff[i]);
			//line[fetich][x] = buff[i];
			x++;
			i++;
			if (buff[i] == '\n')
				return (1);
		}
		i++;
	}
	if (buff[i] == '\0')
		return (0);
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE];
	static int	fetich = 0;
	int			num;
	int			x;
	int			tst;

	x = 0;
	num = read(fd, buff, (BUFF_SIZE));
	buff[num] = '\0';
	line = (char**)malloc(sizeof(char) * fetich);
	while (x < fetich)
		line[x++] = (char *)malloc(sizeof(char) * until_n(buff, fetich));
	tst = get_line(buff, line, fetich);
	ft_putchar('\n');
	fetich++;
	free(line);
	return (tst);
}
