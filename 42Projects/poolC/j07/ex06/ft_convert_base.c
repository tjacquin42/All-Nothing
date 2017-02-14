/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 16:42:54 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/29 17:24:34 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *base)
{
	int			i;
	int			j;

	i = 0;
	j = i + 1;
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
					|| base[j] == '+' || base[j] == '-')
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	if (i <= 1)
		return (1);
	return (i);
}

int		stri_is_good(char h, char *base, int bol)
{
	int			u;
	int			y;
	int			x;

	x = 0;
	u = 0;
	y = 0;
	if (bol == 1)
	{
		while (base[u] != '\0')
		{
			if (base[u] == h)
				y++;
			u++;
		}
		if (y == 1)
			return (0);
		else
			return (1);
	}
	while (base[x] != h)
		x++;
	return (x);
}

int		test_str(char *str, char *base)
{
	int			m;
	int			n;
	int			ok;

	ok = 0;
	m = 0;
	n = 0;
	while (str[m] != '\0')
	{
		ok = 0;
		while (base[n] != '\0' && ok == 0)
		{
			if (str[m] == base[n])
				ok++;
			if (m == 0 && (str[0] == '+' || str[0] == '-'))
				ok++;
			n++;
		}
		if (ok == 0)
			return (1);
		m++;
		n = 0;
	}
	return (0);
}

char	*itoa_chelou(int nbr, char *base)
{
	char		*ret;
	int			temp_n;
	long int	size_ret;
	char		sign;

	if (ft_strlen(base) < 2)
		return (NULL);
	sign = (nbr < 0) ? -1 : 1;
	size_ret = 2 + (nbr < 0);
	temp_n = nbr;
	while ((nbr = nbr / (ft_strlen(base))))
		size_ret++;
	nbr = temp_n;
	if ((ret = (char *)malloc(sizeof(char) * size_ret--)) == NULL)
		return (NULL);
	ret[size_ret--] = '\0';
	ret[size_ret--] = sign * base[nbr % ft_strlen(base)];
	while ((nbr = nbr / (ft_strlen(base))))
		ret[size_ret--] = sign * base[nbr % ft_strlen(base)];
	if (sign < 0)
		ret[size_ret] = '-';
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			nb;
	int			i;
	int			sg;

	nb = 0;
	i = 0;
	sg = 1;
	if (ft_strlen(base_from) <= 1 || test_str(nbr, base_from) == 1)
		return (0);
	while ((nbr[i] == ' ') || (nbr[i] == '	'))
		i++;
	if ((nbr[i] == '-') || (nbr[i] == '+'))
	{
		if (nbr[i] == '-')
			sg *= -1;
		i++;
	}
	while (nbr[i] != '\0')
	{
		if (stri_is_good(nbr[i], base_from, 1))
			return (itoa_chelou(nb * sg, base_to));
		nb = nb * ft_strlen(base_from) + (stri_is_good(nbr[i], base_from, 0));
		i++;
	}
	return (itoa_chelou(nb * sg, base_to));
}
