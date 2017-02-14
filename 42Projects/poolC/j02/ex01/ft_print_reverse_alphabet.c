/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 16:08:54 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/16 16:09:17 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	int z;

	z = 'z';
	while (z > ('a' - 1))
	{
		ft_putchar(z);
		z--;
	}
}
