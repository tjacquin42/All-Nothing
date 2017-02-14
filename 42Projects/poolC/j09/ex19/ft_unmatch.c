/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 09:28:05 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/23 16:33:23 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int  ft_unmatch(int *tab, int length)
{
	int  i;
	int  j;
	int  k;

	i = 0;
	while (i < length)
	{
		j = 0;
		k = 0;
		while (j < length)
		{
			if (tab[j] == tab[i])
				k++;
			j++;
		}
		if (k % 2 == 1)
			return (tab[i]);
		i++;
	}
	return (0);
}
