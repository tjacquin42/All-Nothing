/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 04:46:46 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/25 06:37:57 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_params(char *tab)
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

	j = 1;
	while (argc > j)
	{
		ft_print_params(argv[j]);
		j++;
	}
	return (0);
}
