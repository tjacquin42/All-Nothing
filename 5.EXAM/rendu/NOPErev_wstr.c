/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:55:58 by tjacquin          #+#    #+#             */
/*   Updated: 2017/03/20 20:13:55 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	puta(char c)
{
	write(1, &c, 1);
}

int		lenword(char *str)
{
	int i = 0;
	int count = 0;

	if (str[0] == ' ')
	{
		while (str[i] == ' ')
			i++;
	}
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			count++;
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**next_len(char *str, char **tab, int a)
{
	int		i = a;
	int		count = 0;
	int		c = 0;
	char	*temp = NULL;
	int		t = 0;

	if (str[0] == ' ')
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
	}
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i])
			{
				temp[t] = str[i];
				puta(temp[t]);
				count++;
				i++;
				t++;
			}
			temp[t] = '\n';
			tab[c] = (char *)malloc(sizeof(char) * count + 1);
			tab[c] = temp;
			c++;
			count = 0;
		}
		else
			i++;
	}
	return (tab);
}

char	**chain(char *str)
{
	int a = 0;
	char **tab = NULL;

	tab = (char **)malloc(sizeof(char *) * lenword(str));
	tab = next_len(str, tab, a);
	return (tab);
}

void	putit(char *str)
{
	char	**tab;
	int		i;
	int		a = 0;

	i = lenword(str);
	tab = chain(str);
	printf("%d\n", i);
	while (i > 0)
	{
		puta(tab[i][a]);
		while (a < 2)
		{
			ft_putstr(&tab[i][a]);
			a++;
		}
		puta('\n');
		a = 0;
		i--;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		putit(argv[1]);
	}
	ft_putstr("\n");
	return (0);
}
