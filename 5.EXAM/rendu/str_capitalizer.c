/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:33:11 by tjacquin          #+#    #+#             */
/*   Updated: 2016/03/24 16:03:29 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	toup(char *str, int i)
{
	if (str[i] >= 97 && str[i] <= 122)
		str[i] = str[i] - 32;
}

void	tolow(char *str, int i)
{
	if (str[i] >= 65 && str[i] <= 90)
		str[i] = str[i] + 32;
}

void	capit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i - 1] == ' ' || str[i - 1] == '\t' || i == 0)
			toup(str, i);
		else if (str[i] != ' ')
			tolow(str, i);
		putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		capit(argv[i]);
		i++;
		putchar('\n');
	}
	return (0);
}
