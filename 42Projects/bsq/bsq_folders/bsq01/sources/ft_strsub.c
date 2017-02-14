/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 14:55:30 by mnicolas          #+#    #+#             */
/*   Updated: 2016/02/06 16:51:22 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*res;

	i = start;
	j = 0;
	if (s)
	{
		res = (char *)malloc(sizeof(char) * (len + 1));
		if (res == NULL)
			return (res);
		while (j < len)
		{
			res[j] = s[i];
			i++;
			j++;
		}
		res[j] = '\0';
		return (res);
	}
	else
		return (NULL);
}
