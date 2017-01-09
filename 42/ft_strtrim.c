/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:05:32 by tjacquin          #+#    #+#             */
/*   Updated: 2016/04/04 15:44:06 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*process_strtrim(char const *s, char *str)
{
	int	i;
	int	j;
	int	max;
	int	min;

	i = 0;
	j = 0;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	min = j;
	while (s[j + 1] != '\0')
		j++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	max = j + 1;
	while (min < max)
	{
		str[i] = s[min];
		i++;
		min++;
	}
	return (str);
}

#include <stdio.h>
static int	nb_space(char const *s)
{
	int	i;
	int	nb;
	int	save;

	i = 0;
	nb = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	nb = i;
	while (s[i + 1] != '\0')
		i++;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	save = i;
	printf("%lu", save - nb + 1);
	return (save - nb + 1);
}

char		*ft_strtrim(char const *s)
{
	int	i;
	char	*str;

	i = 0;
	if (s)
	{
		str = (char *)malloc(sizeof(char) + nb_space(s));
		if (!str)
			return (NULL);
		str = process_strtrim(s, str);
		write(1, str, strlen(str));
		return (str);
	}
	else
		return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_strtrim(argv[1]);
	}
	return (0);
}
