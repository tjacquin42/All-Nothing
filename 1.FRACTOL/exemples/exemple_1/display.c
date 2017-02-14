/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:33:35 by dchristo          #+#    #+#             */
/*   Updated: 2016/09/10 23:38:05 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_env *e)
{
	int		pos;

	pos = (e->x * e->img.bpp / 8) + (e->y * e->img.sl);
	e->img.img[pos] = (int)(e->color.z * 256);
	e->img.img[pos + 1] = ((int)(e->color.y * 256));
	e->img.img[pos + 2] = ((int)(e->color.x * 256));
}
