#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
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
	int				zoom;
	int				xmax;
	int				ymax;
	float			hi;
	float			*x_p;
	float			*y_p;
	float			*z_p;
	float			rx;
	float			ry;
	float			rz;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				x1cp;
	int				y1cp;
	int				x2cp;
	int				y2cp;
	int				bpx;
	int				szl;
	int				endl;
	int				size_win;
	int				decal_x;
	int				decal_y;
}					fdf_t;

void				map_trace(fdf_t *stk);
void				segment_tracer(fdf_t *stk);
float				d_r(float deg);
int					img_gen(int keycode, fdf_t *stk);
int					nbrlen(char *ln);
void				display(void);
int					get_center(fdf_t *stk);

#endif
