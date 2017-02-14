/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 04:31:31 by tjacquin          #+#    #+#             */
/*   Updated: 2015/11/03 18:32:40 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		p;

	p = 0;
	while (str[p] != '\0')
	{
		ft_putchar(str[p]);
		p++;
	}
}

int		ft_atoi(char *str)
{
	int		nb;
	int		i;
	int		sg;

	nb = 0;
	i = 0;
	sg = 1;
	while ((str[i] == ' ') || (str[i] == '	'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '+')
			sg *= -1;
		sg *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if ((str[i] > '9') || (str[i] < '0'))
			return (nb * sg);
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	return (nb * sg);
}

void	ft_putnbr(int nb)
{
	char	*str;
	int		i;

	i = 0;
	if (nb == -2147483648)
	{
		str = "-2147483648";
		while (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = nb * -1;
		}
		if (nb >= 10)
			ft_putnbr(nb / 10);
		ft_putchar('0' + (nb % 10));
	}
}
