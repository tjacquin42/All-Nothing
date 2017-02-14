/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 23:24:56 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/22 23:24:58 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ultimator.h"
#include <stdlib.h>

void	ft_destroy(char ***factory)
{
	int a;
	int b;

	a = -1;
	while (factory[++a])
	{
		b = -1;
		while (factory[++b])
			free(factory[a][b]);
		free(factory[a]);
	}
	free(factory);
}
