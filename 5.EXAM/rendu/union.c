/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:20:36 by tjacquin          #+#    #+#             */
/*   Updated: 2016/03/24 09:37:03 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

int		checki(char *big, char *litle, char let, int c)
{
	int i;

	i = 0;
	while (litle[i] != '\0')
	{
		if (litle[i] == let)
			return (0);
		i++;
	}
	i = 0;
	while (c > i)
	{
		if (big[i] == let)
			return (0);
		i++;
	}
	return (1);
}

int		check(char *str, char let, int c)
{
	int i;

	i = 0;
	while (c > i)
	{
		if (str[i] == let)
			return (0);
		i++;
	}
	return (1);
}

void	onion(char *litle, char *big)
{
	int		i;
	int		v;

	i = 0;
	v = 0;
	while (litle[v] != '\0')
	{
		if (check(litle, litle[v], v) == 1)
			putchar(litle[v]);
		v++;
	}
	while (big[i] != '\0')
	{
		if (checki(big, litle, big[i], i) == 1)
			putchar(big[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		onion(argv[1], argv[2]);
	putchar('\n');
	return (0);
}
