/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckupfers <ckupfers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:12:04 by ckupfers          #+#    #+#             */
/*   Updated: 2015/12/10 22:01:22 by ckupfers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

t_list	ft_change(t_list pn)
{
	int		i;

	i = -1;
	while (++i < 16)
	{
		pn.p[i] = pn.n[i];
		pn.n[i] = '\0';
	}
	return (pn);
}

t_list	ft_init(t_list pn)
{
	int		i;

	i = -1;
	while (++i < 16)
	{
		pn.p[i] = '\0';
		pn.n[i] = '\0';
	}
	return (pn);
}

int		ft_mainbis(t_list a, t_list pn, char *av)
{
	char	buffer;
	int		c;

	c = 1;
	if (ft_strcmp(av, "-C") == 0)
		c = 0;
	while (read(a.fd, &buffer, 1) != 0)
	{
		pn.n[a.char16] = buffer;
		a.char16++;
		a.ctt++;
		if (a.char16 == 16)
		{
			a.star = print(pn, a.ctt - a.char16, a.star, c);
			a.char16 = 0;
			pn = ft_change(pn);
		}
	}
	if (pn.n[0] != '\0')
		print(pn, a.ctt - a.char16, 0, c);
	return (a.ctt);
}

int		ft_error(int ac, char **av, int i)
{
	ft_putstr("hexdump: ");
	ft_putstr(av[i]);
	ft_putstr(": No such file or directory\n");
	if (i == ac - 1)
	{
		ft_putstr("hexdump: ");
		ft_putstr(av[i]);
		ft_putstr(": Bad file descriptor\n");
	}
	return (-10);
}

int		main(int argc, char **argv)
{
	t_list	a;
	t_list	pn;

	a.i = 0;
	if (ft_strcmp(argv[1], "-C") == 0)
		a.i = 1;
	a.char16 = 0;
	a.ctt = 0;
	a.star = 0;
	pn = ft_init(pn);
	while (++a.i < argc)
	{
		a.fd = open(argv[a.i], O_RDONLY);
		if (a.fd >= 0)
			a.ctt = ft_mainbis(a, pn, argv[1]);
		else
			a.ctt = ft_error(argc, argv, a.i);
	}
	if (a.ctt != -10)
	{
		ft_numchar(a.ctt, ft_strcmp(argv[1], "-C"));
		ft_putchar('\n');
	}
	close(a.fd);
	return (0);
}
