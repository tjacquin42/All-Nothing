/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/03 15:39:07 by mnicolas          #+#    #+#             */
/*   Updated: 2016/02/06 18:33:26 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strdup(const char *s)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen((char *)(s)) + 1));
	if (!res)
		return (NULL);
	res = ft_strcpy(res, s);
	return (res);
}
