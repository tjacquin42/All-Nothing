/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 05:14:50 by tjacquin          #+#    #+#             */
/*   Updated: 2015/11/03 05:15:32 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	my_swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		done;
	int		i;

	done = 0;
	while (!done)
	{
		done = 1;
		i = 0;
		while (tab[++i])
			if (cmp(tab[i - 1], tab[i]) > 0)
			{
				my_swap(tab + i - 1, tab + i);
				done = 0;
			}
	}
}
