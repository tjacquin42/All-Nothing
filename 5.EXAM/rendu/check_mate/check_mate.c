/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:55:16 by tjacquin          #+#    #+#             */
/*   Updated: 2017/03/15 20:38:22 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include <stdio.h>

void	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
		write(1, &str[i++], 1);
}

int		ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

void	fail(char **str)
{
	ft_putstr("Fail");
	exxit(str);
}

void	success(char **str)
{
	ft_putstr("Success");
	exxit(str);
}

void	parse(char **str, int size)
{
	int a = 0;
	int i = 0;
	int ret = 0;
	while (i != size)
	{
		while (a <= size)
		{
			if (str[i][a] == 'P')
				ret = pawn(str, i, a, size);
			if (str[i][a] == 'B')
				ret = bishop(str, i, a, size);
			if (str[i][a] == 'R')
				ret = rook(str, i, a, size);
			if (str[i][a] == 'Q')
				ret = queen(str, i, a, size);
			a++;
		}
		i++;
		a = 0;
	}
	if (ret > 0)
		success(str);
	else if (ret == 0)
		fail(str);
}

void	test(char **tab, int size)
{
	int k = 0;
	int i = 0;
	int a = 0;

	while (i != size)
	{
		while (a <= size)
			k = ((tab[i][a++] == 'K') ? (k = k + 1) : k);
		i++;
		a = 0;
	}
	if (k < 1 || k > 1)
		exxit(tab);
}

int		main(int argc, char **argv)
{
	int		i = 1;
	char	**tab = NULL;
	int		size;

	if (argc > 1)
	{
		size = ft_strlen(argv[1]);
		if (size != argc - 1)
			exxit(tab);
		if (!(tab = (char **)malloc(sizeof(char *) * argc - 1)))
				exxit(tab);
		while (argv[i])
		{
			if (size != ft_strlen(argv[i]))
					exxit(tab);
			if (!(tab[i] = (char *)(sizeof(char) * size)))
				exxit(tab);
			tab[i - 1] = argv[i];
			i++;
		}
		test(tab, size);
		parse(tab, size);
	}
	else
		ft_putstr("\n");
	return (0);
}
