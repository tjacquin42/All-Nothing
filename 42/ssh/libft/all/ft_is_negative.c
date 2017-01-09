/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 16:11:31 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/16 16:11:38 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_putchar(char c);

void	ft_is_negative(int n)
{
	char a;
	char b;

	a = 'N';
	b = 'P';
	if (n < 0)
		ft_putchar(a);
	else
		ft_putchar(b);
}
