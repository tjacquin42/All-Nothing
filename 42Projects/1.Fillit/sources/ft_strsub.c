/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blo <blo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 09:15:48 by blo               #+#    #+#             */
/*   Updated: 2016/06/04 13:45:43 by blo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strsub(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*res;

	i = start;
	j = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	while (j < len)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}
