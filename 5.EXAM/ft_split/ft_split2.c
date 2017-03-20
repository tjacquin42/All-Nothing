/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:49:43 by tjacquin          #+#    #+#             */
/*   Updated: 2017/03/15 22:30:43 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <unistd.h>
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

int		no_space(char *str)
{
	int i		= 0;
	int count	= 0;

	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
		{;
			if (str[i - 1] == ' ' || str[i - 1] == '\t' ||
					str[i - 1] == '\n' || i == 0)
				count++;
			i++;
		}
	}
	return (count);
}

int		ft_nextword(char *str, int i, int a)
{

	return (i);
}

int		ft_lenword(char *str, int i)
{
	int j = 0;

	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
		i++;
	while ((str[i] != ' ' || str[i] != '\t' || str[i] != '\n') && str[i])
	{
		i++;
		j++;
	}
	return (j);
}

char	**ft_split(char *str)
{
	char	**tab	= NULL;
	int		i		= 0;
	int		j		= 0;
	int		a		= 0;

	if (!(tab = (char**)malloc(sizeof(char*) * no_space(str) + 1)))
		return (0);
	printf("no = %d\n", no_space(str));
	while (str[i])
	{
		i = ft_nextword(str, i, a);
		printf("val = %d\n", i);
		tab[a] = (char*)malloc(sizeof(char) * ft_lenword(str, i));
		a++;
	}

	int b = 0;
	b = ft_nextword(str, i, a);
	i = 0;
	while (tab[i][j] != '\0')
	{
		j = 0;
		while (tab[i][j] != '\n')
		{
			tab[i][j] = str[a];
			write(1, &tab[i][j], 1);
			j++;
			a++;
		}
		i++;
	}

	return (tab);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		ft_split(argv[1]);
	return (0);
}
