/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:45:49 by ghubert           #+#    #+#             */
/*   Updated: 2017/01/26 17:03:49 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"
#include <math.h>

int			deg_to_rad(int deg)
{
	return((deg * pi) / 180);
}

void		rot_x(int x, int y, int z, int deg)
{
	int		xp;
	int		yp;
	int		zp;

	xp = x;
	yp = (cos(deg_to_rad(deg)) * y) - (sin(deg_to_rad(deg)) * z);
	zp = (sin(deg_to_rad(deg)) * y) - (cos(deg_to_rad(deg)) * z);
}
