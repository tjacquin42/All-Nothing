/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifpar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:50:03 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/16 18:14:29 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		verifpar(char *par)
{
	int i;

	i = 0;
	if (par[0] == par[1])
	{
		write(1, "map error\n", 10);
		return (0);
	}
	if (par[1] == par[2])
	{
		write(1, "map error\n", 10);
		return (0);
	}
	if (par[0] == par[2])
	{
		write(1, "map error\n", 10);
		return (0);
	}
	return (1);
}
