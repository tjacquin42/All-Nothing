/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 18:28:40 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/11 18:29:02 by tjacquin         ###   ########.fr       */
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
