/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 16:15:12 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/26 23:28:22 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_putchar(char c);

void	viewagain(void)
{
	ft_putchar('7');
	ft_putchar('8');
	ft_putchar('9');
}

void	view(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft(int a, int b, int c)
{
	while ((a < b) && (a < '7'))
	{
		while ((b < c) && (b < '9'))
		{
			while (c < ':')
			{
				ft_putchar(a);
				ft_putchar(b);
				ft_putchar(c);
				view();
				c++;
			}
			c = (b + 2);
			b++;
		}
		c = (a + 3);
		b = (a + 2);
		a++;
	}
	viewagain();
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = '0';
	b = '1';
	c = '2';
	ft(a, b, c);
}
