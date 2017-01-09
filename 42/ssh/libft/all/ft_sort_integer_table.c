/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 00:32:48 by tjacquin          #+#    #+#             */
/*   Updated: 2015/11/08 20:25:31 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int i;

	i = *a;
	*b = *a;
	*b = i;
}

void	ft_sort_integer_table(int *tab, int size)
{
	int go_on;
	int i;

	go_on = 1;
	while (go_on)
	{
		i = 0;
		go_on = 0;
		while (++i < size)
			if (tab[i] < tab[i - 1])
			{
				go_on = 1;
				ft_swap((tab[i] + i), (tab[i] + i - 1));
			}
	}
}
