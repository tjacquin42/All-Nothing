/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 14:18:38 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/17 14:22:15 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	{
		if (power < 0)
			return (0);
		if (power == 0)
			return (1);
		if (power > 1)
			nb = ft_recursive_power(nb, power - 1) * nb;
	}
	return (nb);
}
