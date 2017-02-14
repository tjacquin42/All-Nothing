/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 14:57:19 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/23 14:59:24 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	int ans;

	ans = 0;
	while (value > 0)
	{
		ans += value % 2;
		value /= 2;
	}
	return (ans);
}
