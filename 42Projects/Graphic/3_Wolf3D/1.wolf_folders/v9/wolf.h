/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:25:58 by tjacquin          #+#    #+#             */
/*   Updated: 2017/06/12 17:04:13 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WOLF3D_H
# define WOLF3D_H
# include <stdlib.h>
# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <time.h>

# define W 1280
# define H 720
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ECHAP 53
# define SPRINT 257
# define TURN_SPEED 0.06
# define FOV 66
# define COLOR_1 0x99CCFF
# define COLOR_2 0x9933CC
# define COLOR_3 0xFFCC00
# define COLOR_4 0x66F0F0
# define COLOR_5 0x0000CC
# define COLOR_6 0x009900
# define COLOR_7 0x33FF33
# define COLOR_8 0x660099
# define COLOR_9 0x660000
# define COLOR_10 0x3333FF

typedef struct	s_all
{
	void		*win;
	void		*mlx;
	int			bpx;
	int			size;
	char		*data_addr;
	void		*img;
	int			idgaf;
	double		player_pos_x;
	double		player_pos_y;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			player_moving_up;
	int			player_moving_down;
	int			player_moving_left;
	int			player_moving_right;
	int			**map;
	int			dens;
	double		move_speed;
	int			which;
}				t_all;

void			ray_caster(t_all *truc, int x);
void			find_walls(t_all *truc);
int				loop_hook(t_all *truc);
int				key_input(int keycode, t_all *truc);
int				mouse_input(int keycode, int x, int y, t_all *truc);
void			draw_vertical(t_all *truc, int x);
void			move_up(t_all *truc);
void			move_down(t_all *truc);
void			move_right(t_all *truc);
void			move_left(t_all *truc);
int				echap_key(t_all *truc);
void			init_map_2(t_all *truc, int x, int y, int i);
int				key_input_2(int keycode, t_all *truc);
int				exit_redcross(t_all *truc);
void			init_map(t_all *truc, int x, int y);

#endif
