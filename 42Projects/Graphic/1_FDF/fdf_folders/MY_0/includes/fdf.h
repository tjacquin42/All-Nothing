/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:17:03 by tjacquin          #+#    #+#             */
/*   Updated: 2017/01/26 19:17:07 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include ".././libft/libft.h"
# include <math.h>
# include <stdlib.h>

# define pi 3.1415926535898

typedef struct		fdf_s
{
	void			*win;
	void			*mlx;
	void			*gda;
	void			*img;
	int				**map;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				ply;
	int				plx;
	int				bpx;
	int				szl;
	int				endl;
	int				xcp;
	int				ycp;
}					fdf_t;

void				seg_tracer(fdf_t stk);
void				get_map();

#endif
