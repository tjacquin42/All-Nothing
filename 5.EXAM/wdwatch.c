/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdwatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:32:10 by tjacquin          #+#    #+#             */
/*   Updated: 2016/03/23 15:17:12 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putstr(char *litl)
{
	int i;

	i = 0;
	while (litl[i] != '\0')
	{
		putchar(litl[i]);
		i++;
	}
}

void	wdwatch(char *litl, char *big)
{
	int i;
	int v;

	i = 0;
	v = 0;
	while (big[v] != '\0' && litl[i] != '\0')
	{
		if (big[v] == litl[i])
			i++;
		v++;
	}
	if (litl[i] == '\0')
		putstr(litl);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		wdwatch(argv[1], argv[2]);
	putchar('\n');
	return (0);
}
