/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_puter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:17:50 by tjacquin          #+#    #+#             */
/*   Updated: 2017/01/26 19:17:52 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		seg_tracer(fdf_t stk)
{
	int		dx;
	int		dy;
	int		err;

	err = stk.x2 - stk.x1;
	dx = err * 2;
	dy = (stk.y2 - stk.y1) * 2;
	while (stk.x1 <= stk.x2)
	{
		stk.ycp = stk.y1 * stk.szl;
		stk.xcp = stk.x1 * stk.bpx / 8;
		*(unsigned*)(stk.gda + (int)stk.ycp + (int)stk.xcp) = 0xffffff;
		stk.x1 = stk.x1 + 1;
		if ((err = err - dy) <= 0)
		{
			stk.y1 = stk.y1 + 1;
			err = err + dx;
		}
	}
}
