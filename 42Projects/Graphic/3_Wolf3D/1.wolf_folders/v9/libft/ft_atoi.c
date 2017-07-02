/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 18:06:32 by tjacquin          #+#    #+#             */
/*   Updated: 2017/06/12 17:25:54 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int	ft_checking(char c)
{
	if (c == '\n' || c == '\v' || c == '\r')
		return (1);
	else if (c == '\t' || c == ' ' || c == '\f')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int rng;
	int signe;
	int transformateur;

	rng = 0;
	transformateur = 0;
	signe = 1;
	while (ft_checking(str[rng]) == 1)
		rng++;
	if (str[rng] == '-' || str[rng] == '+')
	{
		signe = (str[rng] == '-' ? -1 : 1);
		rng++;
	}
	while (ft_isdigit(str[rng]))
	{
		transformateur = transformateur * 10 + str[rng] - 48;
		rng++;
	}
	return (transformateur * signe);
}
