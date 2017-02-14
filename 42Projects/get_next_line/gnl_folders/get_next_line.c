/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 22:01:29 by tjacquin          #+#    #+#             */
/*   Updated: 2016/12/05 19:02:44 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.next.line/get_next_line.h"

int		strleni(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		lenline(char **leni, int fetich)
{
	int y;

	y = 0;
	while (leni[fetich][y] != '\n')
		y++;
	return (y);
}

char	*next(char **str, int fetich)
{
	char		*one;
	int			i;

	i = 0;
	one = (char *)malloc(sizeof(char) * lenline(str, fetich));
	while (str[fetich][i] != '\n')
	{
		one[i] = str[fetich][i];
		i++;
	}
	free(str);
	one[i] = '\0';
	return (one);
}

char	**get_line(const int fd, int fetich, char **all)
{
	char	buff[BUFF_SIZE + 1];
	int		i;
	int		x;
	int		y;
	int		num;

	x = 0;
	num = read(fd, buff, BUFF_SIZE);
	buff[num] = '\0';
	close(fd);
	all = (char **)malloc(sizeof(char *) * ft_strlen(buff));
	while (x < ft_strlen(buff))
		all[x++] = (char *)malloc(sizeof(char) * ft_strlen(buff));
	x = 0;
	i = -1;
	while (buff[++i] != '\0')
	{
		y = 0;
		while (buff[i] != '\n')
		{
			all[x][y++] = buff[i++];
			ft_putchar(all[x][y]);
		}
		all[x++][y] = '\n';
	}
	all[x][y] = '\0';
	if (fetich >= x)
		return (NULL);
	return (all);
}

int		get_next_line(const int fd, char **line)
{
	char		*one;
	static int	fetich = 0;

	if ((fd < 0 || fd == 1 || fd == 2))
		return (-1);
	line = get_line(fd, fetich, line);
	if (line == NULL)
		return (0);
	one = next(line, fetich);
	fetich++;
	return (1);
}
