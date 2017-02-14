/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 04:15:24 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/25 05:47:44 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_rev_params(char *tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
	{
		ft_putchar(tab[i]);
		i++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int j;
	int n;

	n = 0;
	j = 1;
	while (argc > j)
	{
		n++;
		j++;
	}
	j = 0;
	while (n != 1 - 1)
	{
		ft_rev_params(argv[j + n]);
		n--;
	}
	return (0);
}
