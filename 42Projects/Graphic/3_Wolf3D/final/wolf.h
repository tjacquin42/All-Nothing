/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:25:58 by tjacquin          #+#    #+#             */
/*   Updated: 2017/06/12 20:34:31 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdlib.h>
# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <time.h>

# define W 1280
# define H 720
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ECHAP 53
# define SPRINT 257
# define TURN_SPEED 0.06
# define FOV 66
# define COLOR_1 0x01B8FF
# define COLOR_2 0xB933CC
# define COLOR_3 0xFFF100
# define COLOR_4 0xFF7B77
# define COLOR_5 0xB1F200
# define COLOR_6 0xFFAB55
# define WALL_1 0xF8F8FF
# define WALL_2 0xF0FFFF
# define WALL_3 0xF5F5DC
# define WALL_4 0xFFE4E1
# define SKY 0x39EBD7
# define FLOOR 0xFFB42C

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
void			destroy_cube(t_all *truc);
void			create_cube(t_all *truc);
void			init_map(t_all *truc, int x, int y);

#endif
