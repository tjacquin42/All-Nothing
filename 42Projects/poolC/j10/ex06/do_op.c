/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 04:18:33 by tjacquin          #+#    #+#             */
/*   Updated: 2015/11/03 18:31:03 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		opp(char *str)
{
	int		i;
	int		u;

	i = 42;
	u = 0;
	while (str[u])
		u++;
	if (u == 1)
	{
		if (str[0] == '+')
			i = 0;
		else if (str[0] == '-')
			i = 1;
		else if (str[0] == '*')
			i = 2;
		else if (str[0] == '/')
			i = 3;
		else if (str[0] == '%')
			i = 4;
	}
	return (i);
}

int		test_error(int b, int op)
{
	if (b == 0 && op == 3)
	{
		ft_putstr("Stop : division by zero");
		return (1);
	}
	else if (b == 0 && op == 4)
	{
		ft_putstr("Stop : modulo by zero");
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		a;
	int		b;
	int		op;
	int		(*l[5])(int, int);

	l[0] = &add;
	l[1] = &sou;
	l[2] = &mul;
	l[3] = &div;
	l[4] = &mod;
	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	op = opp(argv[2]);
	if (op < 0 || op > 4)
	{
		ft_putnbr(0);
		ft_putchar('\n');
		return (0);
	}
	if (test_error(b, op) == 0)
		ft_putnbr(l[op](a, b));
	ft_putchar('\n');
	return (0);
}
