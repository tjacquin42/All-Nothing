/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckupfers <ckupfers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:12:04 by ckupfers          #+#    #+#             */
/*   Updated: 2015/12/10 22:01:22 by ckupfers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int		ft_check(char p[16], char n[16])
{
	int	i;

	i = 0;
	while (p[i] == n[i])
		i++;
	if (i == 16)
		return (1);
	return (0);
}

void	ft_special(char c)
{
	if (c == '	')
		ft_putchar('.');
	else if (c == '\n')
		ft_putchar('.');
	else if (c == '\0')
		return ;
	else
		ft_putchar(c);
}

int		print_bis(int i, int c, char n[16])
{
	if (c == 0)
		ft_putstr("  ");
	else
		ft_putchar(' ');
	while (++i < 16)
	{
		ft_hexa(n[i]);
		if (i != 15 || c == 0)
			ft_putchar(' ');
		if ((i == 7 || i == 15) && c == 0)
			ft_putchar(' ');
	}
	return (i);
}

int		print(t_list pn, int nbchar, int star, int c)
{
	int	i;

	i = -1;
	if (ft_check(pn.p, pn.n) == 1)
	{
		if (star != 1)
			ft_putstr("*\n");
		return (1);
	}
	star = 0;
	ft_numchar(nbchar, c);
	i = print_bis(i, c, pn.n);
	if (c == 0)
	{
		i = -1;
		ft_putchar('|');
		while (++i < 16)
			ft_special(pn.n[i]);
		ft_putchar('|');
	}
	ft_putchar('\n');
	return (0);
}
