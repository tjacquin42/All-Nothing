/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thisend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 23:20:53 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/16 18:42:08 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	this_is_the_end(char *grille, char *param)
{
	ft_putstr(grille);
	free(grille);
	free(param);
}
