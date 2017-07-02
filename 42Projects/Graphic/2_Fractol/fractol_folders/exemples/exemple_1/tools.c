/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:34:09 by dchristo          #+#    #+#             */
/*   Updated: 2016/02/19 15:06:23 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vec3		palette(double x, int theme)
{
	t_vec3	color;

	color.x = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (theme == 0));
	color.y = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (theme == 1));
	color.z = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (theme == 2));
	return (color);
}

double		scaledy(t_env *e, int y)
{
	double dy;

	dy = (((e->ytop - e->ybot) * y) / e->img.height) + e->ybot;
	return (dy);
}

double		scaledx(t_env *e, int x)
{
	double dx;

	dx = (((e->xtop - e->xbot) * x) / e->img.height) + e->xbot;
	return (dx);
}
