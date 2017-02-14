#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include ".././libft/libft.h"

# define pi 3.1415926535898
# define ROTX 1
# define ROTY 2
# define ROTZ 3

typedef struct		fdf_s
{
	void			*win;
	void			*mlx;
	void			*gda;
	void			*img;
	char			*path;
	int				ln;
	int				color;
	int				**map;
	int				x_p;
	int				y_p;
	int				z_p;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				x1cp;
	int				y1cp;
	int				x2cp;
	int				y2cp;
	int				ply;
	int				plx;
	int				bpx;
	int				szl;
	int				endl;
	int				nb_max;
}					fdf_t;


fdf_t				*print_squares(int nb, int nb2, int x, int y, fdf_t *stk);
void				segment_tracer(fdf_t *stk);
int					img_gen(int keycode, fdf_t *stk);
fdf_t				*rot_server(int axis, int deg, fdf_t *stk);
int					main_event(int keycode, fdf_t *stk);
int					nbrlen(char *ln);

#endif
