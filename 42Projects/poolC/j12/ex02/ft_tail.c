/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckupfers <ckupfers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:12:04 by ckupfers          #+#    #+#             */
/*   Updated: 2015/12/10 22:01:22 by ckupfers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"
#include <fcntl.h>

int		sizef(char *n)
{
	char	c;
	int		fd;
	int		size;

	size = 0;
	fd = open(n, O_RDONLY);
	if (fd >= 0)
		while (read(fd, &c, 1) != 0)
			size++;
	close(fd);
	return (size);
}

void	nameprint(int i, int ac, char **av)
{
	int	j;

	j = 0;
	if (ac > 4)
	{
		if (i > 3)
		{
			write(1, "\n==> ", 5);
		}
		else
			write(1, "==> ", 4);
		while (av[i][j])
		{
			write(1, &av[i][j], 1);
			j++;
		}
		write(1, " <==\n", 5);
	}
}

void	readf_end(int i, int offset, int ac, char **av)
{
	int		fd;
	int		c;
	int		size;
	int		r;

	r = 0;
	size = sizef(av[i]);
	fd = open(av[i], O_RDONLY);
	nameprint(i, ac, av);
	if (ac == 1 || av[2][0] == '+')
	{
		while (r != offset - 1)
			r += read(fd, &c, 1);
		while (read(fd, &c, 1))
			write(1, &c, 1);
	}
	else
	{
		while (r < (size - offset))
			r += read(fd, &c, 1);
		while (read(fd, &c, 1))
			write(1, &c, 1);
	}
}

void	readf(int i, int offset, int ac, char **av)
{
	int		fd;

	fd = open(av[i], O_RDONLY);
	if (fd >= 0)
		readf_end(i, offset, ac, av);
	else
	{
		ft_putstr("tail: ");
		ft_putstr(av[i]);
		ft_putstr(": No such file or directory\n");
	}
	close(fd);
}

int		main(int ac, char **av)
{
	int		size;
	int		ar;
	int		i;
	int		flag;

	ar = 2;
	flag = 0;
	if (ac < 3)
		return (0);
	else if (ft_strcmp(av[1], "-c") == 0)
	{
		size = ft_atoi(av[2]);
		ar++;
	}
	else
	{
		if (av[1][2] == '+')
			flag = 1;
		size = ft_atoi(av[1]);
	}
	i = ar;
	while (i < ac)
		readf(i++, size, ac, av);
	return (0);
}
