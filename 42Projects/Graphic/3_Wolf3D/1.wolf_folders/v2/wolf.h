/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:25:58 by tjacquin          #+#    #+#             */
/*   Updated: 2017/05/10 19:21:05 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_brd
{
	int				i;
	int				j;
	int				dec_x;
	int				dec_y;
	int				x;
	int				y;
}					t_brd;

typedef struct		s_wo
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*gda;
	int				swin;
	int				endl;
	int				bpx;
	int				szl;
	int				color;
	char			**map;

	int				ply_x;
	int				ply_y;
}					t_wo;

int		parce_map(t_wo *stk);

int		event(int keycode, t_wo *stk);

#endif
