/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 14:56:57 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 15:31:52 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		i;
	int		j;

	if (s)
	{
		i = 0;
		j = ft_strlen(s);
		while (i < j)
		{
			s[i] = '\0';
			i++;
		}
	}
}