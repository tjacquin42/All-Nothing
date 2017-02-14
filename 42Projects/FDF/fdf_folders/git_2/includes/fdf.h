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
	int				**map;
	int				deg;
	int				x_p;
	int				y_p;
	int				z_p;
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

void				seg_tracer(fdf_t *stk);
fdf_t				rot_server(int axis, int deg, fdf_t *stk);
void				get_map(fdf_t *stk);
int					key_change(int a, fdf_t *stk);
void				print_square(void *win, fdf_t *stk);

#endif
