/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 02:30:32 by tjacquin          #+#    #+#             */
/*   Updated: 2015/11/03 02:31:17 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		my_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	my_swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_wordtab(char **tab)
{
	int		done;
	int		i;

	done = 0;
	while (!done)
	{
		done = 1;
		i = 0;
		while (tab[++i])
			if (my_strcmp(tab[i - 1], tab[i]) > 0)
			{
				my_swap(tab + i - 1, tab + i);
				done = 0;
			}
	}
}
