/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 06:30:50 by tjacquin          #+#    #+#             */
/*   Updated: 2015/11/07 17:29:55 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	comb(char *tab, int i)
{
	char n;
	int get;
	int stay;

	get = i;
	stay = get;
	i = 0;
	while (i <= get)
	{
		if (tab[stay] == 9)
		{
			while (tab[get] == (tab[get + 1] - 1))
				get--;
		}
		if (get != i && tab[get] == (tab[get + 1] - 1))
			tab[get] = (tab[get] + 1);
		if (tab[stay] != 9)
			tab[stay] = (tab[stay] + 1);
		while (tab[i] != '\0')
		{
			ft_putchar(tab[i]);
			i++;
		}
		write(1, ", ", 2);
	}
}

void	ft_print_combn(int n)
{
	char *tab;
	int i;
	char a;


	tab = "0123456789";
	 write(1, "putain", 6);

	i = 1;
	while (i != n)
		i++;
	tab[n + 1] = '\0';
	write(1, "a", 1);
	comb(tab, i);
}

int		main(void)
{
	ft_print_combn(3);
	return (0);
}
