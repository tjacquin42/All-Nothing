/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 16:45:17 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/28 16:21:55 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_putchar(char c);

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i < 2)
		return (0);
	return (i);
}

int				test_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i] != '\0')
	{
		if ((str[i] == '-' || str[i] == '+') ||
				(str[0] == '\0' || str[1] == '\0'))
			return (0);
		if (str[i] < 32 || str[i] == 127)
			return (0);
		while (str[j] != '\0')
		{
			if (str[i] == str[j] && str[i] != '\0')
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	unsigned int	temp;

	if (test_base(base) && ft_strlen(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		temp = nbr;
		if (temp >= ft_strlen(base))
		{
			ft_putnbr_base(temp / ft_strlen(base), base);
			ft_putnbr_base(temp % ft_strlen(base), base);
		}
		else
			ft_putchar(base[temp]);
	}
}
