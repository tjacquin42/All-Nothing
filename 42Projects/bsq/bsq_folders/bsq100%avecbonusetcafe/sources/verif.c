/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:54:42 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/17 21:57:39 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		verif(int fd, char *gr, char *par, int i)
{
	int len;
	int lines;

	i = 0;
	len = 0;
	lines = 0;
	if (verifpar(par) == 0)
		return (0);
	while (gr[i] != '\0')
	{
		if (len <= fd && ((gr[i] == par[0]) || (gr[i] == par[1])))
			len++;
		else if (gr[i] == '\n' && len == fd)
		{
			len = 0;
			lines++;
		}
		i++;
	}
	if (lines != fd || i != (fd * fd + fd))
	{
		write(2, "map error\n", 10);
		return (0);
	}
	return (1);
}
