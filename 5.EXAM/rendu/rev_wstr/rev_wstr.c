/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:46:20 by tjacquin          #+#    #+#             */
/*   Updated: 2017/03/14 19:00:03 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static int		ft_strlen(char *tab)
{
	int i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

void		ft_putstr(char *tab)
{
	int i = 0;

	while (tab[i] != '\0')
	{
		write(1, &tab[i], 1);
		i++;
	}
}

int		sizeword(char *str, int i)
{
	int size = 0;

	while ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != '\0')
		i++;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	{
		i++;
		size++;
	}
	return (size);
}

void	cp(char *str1, char *str2, int j)
{
	int i = 0;
	int size = 0;

	while (str1[i] != '\0')
	{
		size = sizeword(str1, i);
		while (size > 0)
		{
			write(1, &str1[i], 1);
			str2[j - size] = str1[i];
			write(1, &str2[j], 1);
			j--;
			size--;
			i++;
		}
		write(1, "\n", 1);
		str2[j] = ' ';
	}
	//ft_putstr(str2);
}

int		main(int argc, char **argv)
{
	int i = 0;
	char *tab2;
	int j = 0;

	if (argc == 2)
	{
		tab2 = (char *)malloc(sizeof(char) * ft_strlen(argv[1]));
		j = ft_strlen(argv[1]);
		cp(argv[1], tab2, j);
	}
	ft_putstr("\n");
	return (0);
}
