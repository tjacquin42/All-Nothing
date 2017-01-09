/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 02:02:01 by tjacquin          #+#    #+#             */
/*   Updated: 2015/11/03 02:02:14 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		way;
	int		tmp;

	way = 0;
	while (--length > 0)
	{
		tmp = f(tab[length - 1], tab[length]);
		if (tmp)
		{
			if (!way && tmp)
				way = tmp > 0 ? 1 : -1;
			if ((tmp > 0 && way == -1) || (tmp < 0 && way == 1))
				return (0);
		}
	}
	return (1);
}
