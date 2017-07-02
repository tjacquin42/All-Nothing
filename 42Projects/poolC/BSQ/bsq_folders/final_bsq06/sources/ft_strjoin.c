/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 18:26:56 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/11 18:27:16 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		size;
	char	*res;

	if (s1 && s2)
	{
		size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
		res = (char *)malloc(sizeof(char) * size + 1);
		if (!res)
			return (NULL);
		i = 0;
		res = ft_strcpy(res, s1);
		res = ft_strcat(res, s2);
		return (res);
	}
	else
		return (NULL);
}
