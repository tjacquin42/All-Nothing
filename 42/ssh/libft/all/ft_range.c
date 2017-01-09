/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 23:33:28 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/29 01:54:20 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *str;
	int i;

	if (max <= min)
		return (0);
	str = (int*)malloc(sizeof(*str) * (max - min));
	i = 0;
	while (i < max - min)
	{
		str[i] = i + min;
		i++;
	}
	return (str);
}
