/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 18:46:09 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/20 19:02:33 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (2);
	while ((nb % i) != 0)
	{
		i++;
	}
	if (nb == i)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}
