#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "libft/libft.h"

typedef struct	s_map {
	int		len;
}				t_map;

typedef struct	s_fdf {
	void	*mlx;
	void	*win;
	t_map	*map;
}				t_fdf;

#endif
