/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 16:20:06 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/16 16:21:54 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	unsigned int	temp;
	int				size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	temp = nb;
	while ((temp /= 10) > 0)
	{
		size *= 10;
	}
	temp = nb;
	while (size)
	{
		ft_putchar((temp / size) + 48);
		temp %= size;
		size /= 10;
	}
}
