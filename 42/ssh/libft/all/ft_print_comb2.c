/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 16:35:08 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/16 16:36:46 by tjacquin         ###   ########.fr       */
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

void	tant(int a, int x)
{
	while (a <= 97)
	{
		while ((x <= 99) && (x != a))
		{
			if (a < 10)
				ft_putchar('0');
			ft_putnbr(a);
			ft_putchar(' ');
			if (x < 10)
				ft_putchar('0');
			ft_putnbr(x);
			ft_putchar(',');
			ft_putchar(' ');
			x++;
		}
		x = (a + 2);
		a++;
	}
	ft_putnbr(98);
	ft_putchar(' ');
	ft_putnbr(99);
}

void	ft_print_comb2(void)
{
	int a;
	int x;

	a = 0;
	x = 1;
	tant(a, x);
}
