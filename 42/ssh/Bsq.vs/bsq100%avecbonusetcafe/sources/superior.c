/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 21:02:26 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/14 21:05:33 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		superior(int left, int up, int diag)
{
	int sup;

	sup = left;
	if (sup > up)
		sup = up;
	if (sup > diag)
		sup = diag;
	return (sup + 1);
}
