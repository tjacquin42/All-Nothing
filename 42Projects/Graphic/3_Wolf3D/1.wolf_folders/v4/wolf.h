/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:25:58 by tjacquin          #+#    #+#             */
/*   Updated: 2017/05/23 14:12:00 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include "./minilibx_macos/mlx.h"
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
	t_brd			*bird;
	void			*mlx;
	void			*win;
	void			*img;
	void			*gda;
	int				swin;
	int				endl;
	int				bpx;
	int				szl;
	int				color;
	int				size_map;
	int				size_box;
	char			**map;

	int				co;
	int				ply_x;
	int				ply_y;
	int				mv_x;
	int				mv_y;
	float			rot_y;
	float			rot_x;
}					t_wo;

void	map_trace(t_wo *s);
int		event(int keycode, t_wo *stk);

#endif
