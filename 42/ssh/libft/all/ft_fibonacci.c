/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 14:22:39 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/20 19:14:00 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if ((index < 0) || (index > 47))
		return (-1);
	if (index < 2)
		return (index);
	if (index >= 0)
		index = ft_fibonacci(index - 2) + ft_fibonacci(index - 1);
	return (index);
}
