/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 01:55:40 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/23 02:20:57 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		powers(char *str)
{
	int		i;
	int		o;
	char	*s1;

	i = 0;
	o = 0;
	s1 = "powers";
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == 'p'))
	{
		if (str[i] == 'p' && (str[i - 1] == ' ' || str[0] == 'p'))
			while (s1[o] != '\0')
			{
				if (s1[o] == str[i])
					o++;
				else if (str[i] == '\0')
					return (0);
				else
					o = 0;
				if (s1[o] == '\0' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
					return (1);
				i++;
			}
		i++;
	}
	return (0);
}

int		attack(char *str)
{
	int		i;
	int		o;
	char	*s1;

	i = 0;
	o = 0;
	s1 = "attack";
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == 'a'))
	{
		if (str[i] == 'a' && (str[i - 1] == ' ' || str[0] == 'a'))
			while (s1[o] != '\0')
			{
				if (s1[o] == str[i])
					o++;
				else if (str[i] == '\0')
					return (0);
				else
					o = 0;
				if (s1[o] == '\0' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
					return (1);
				i++;
			}
		i++;
	}
	return (0);
}

int		president(char *str)
{
	int		i;
	int		o;
	char	*s1;

	i = 0;
	o = 0;
	s1 = "president";
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == 'p'))
	{
		if (str[i] == 'p' && (str[i - 1] == ' ' || str[0] == 'p'))
			while (s1[o] != '\0')
			{
				if (s1[o] == str[i])
					o++;
				else if (str[i] == '\0')
					return (0);
				else
					o = 0;
				if (s1[o] == '\0' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
					return (1);
				i++;
			}
		i++;
	}
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int		main(int argc, char **argv)
{
	int i;

	i = argc - 1;
	while (i > 0)
	{
		ft_strlowcase(argv[i]);
		if (president(argv[i]))
		{
			write(1, "Alert!!!\n", 9);
			return (0);
		}
		if (attack(argv[i]))
		{
			write(1, "Alert!!!\n", 9);
			return (0);
		}
		if (powers(argv[i]))
		{
			write(1, "Alert!!!\n", 9);
			return (0);
		}
		i--;
	}
	return (0);
}
