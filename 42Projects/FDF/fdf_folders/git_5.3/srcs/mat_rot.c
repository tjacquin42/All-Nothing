/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:45:49 by ghubert           #+#    #+#             */
/*   Updated: 2017/02/01 16:29:56 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"
#include <math.h>

static int			d_r(int deg)
{
	return((deg * pi) / 180);
}

static fdf_t		*rot_x(fdf_t *s)
{
	if (s->x_d != 0)
	{
		s->y_p = (cos(d_r(s->x_d)) * (s->y)) - (sin(d_r(s->x_d)) * (s->z));
		s->z_p = (sin(d_r(s->x_d)) * (s->y)) + (cos(d_r(s->x_d)) * (s->z));
	}
	return (s);
}

static fdf_t		*rot_y(fdf_t *s)
{
	if (s->y_d != 0)
	{
		s->x_p = (cos(d_r(s->y_d)) * (s->x)) + (sin(d_r(s->y_d)) * (s->z));
		s->z_p = -(sin(d_r(s->y_d)) * (s->x)) + (cos(d_r(s->y_d)) * (s->z));
	}
	return (s);
}

static fdf_t		*rot_z(fdf_t *s)
{
	if (s->z_d != 0)
	{
		s->x_p = (cos(d_r(s->z_d)) * (s->x)) - (sin(d_r(s->z_d)) * (s->y));
		s->y_p = (sin(d_r(s->z_d)) * (s->x)) + (cos(d_r(s->z_d)) * (s->y));
	}
	return (s);
}

fdf_t				*rot_server(int rotaxis, fdf_t *s)
{
	s->x = s->x1;
	s->y = s->y1;
	s->z = s->z1;
	if (rotaxis == ROTX)
		s = rot_x(s);
	else if (rotaxis == ROTY)
		s = rot_y(s);
	else if (rotaxis == ROTZ)
		s = rot_z(s);
	s->x1 = s->x_p;
	s->y1 = s->y_p;
	s->x = s->x2;
	s->y = s->y2;
	s->z = s->z2;
	if (rotaxis == ROTX)
		s = rot_x(s);
	else if (rotaxis == ROTY)
		s = rot_y(s);
	else if (rotaxis == ROTZ)
		s = rot_z(s);
	s->x2 = s->x_p;
	s->y2 = s->y_p;
	return (s);
}
