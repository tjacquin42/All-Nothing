/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:49:16 by tjacquin          #+#    #+#             */
/*   Updated: 2017/03/14 17:26:10 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
	{
		i++;
	}
	if (i > 9)
		return (-1);
	return (i);
}

int		main(int argc, char **argv)
{
	int nb1;
	int nb2;
	int div;
	int res;

	nb1 = 0;
	nb2 = 0;
	div = 1;
	res = 0;
	if (argc == 3)
	{
		if (ft_strlen(argv[1]) == -1 || ft_strlen(argv[2]) == -1)
		{
			printf("%s", "\n");
			return (0);
		}
		nb1 = atoi(argv[1]);
		nb2 = atoi(argv[2]);
		if (nb1 > 2147483647 && nb1 < -2147483648 &&
				nb2 > 2147483647 && nb2 < 2147483647)
			exit(0);
		while (div < nb1 && div < nb2)
		{
			if ((nb1 % div) == 0 && nb2 % div == 0)
				res = div;
			div++;
		}
		if (res == 0)
			res = 1;
		printf("%d", res);
	}
	printf("%s", "\n");
	return (0);
}
