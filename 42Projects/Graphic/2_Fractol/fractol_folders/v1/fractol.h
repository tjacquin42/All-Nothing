/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 00:59:36 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/23 17:08:36 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define JULIA '1'
# define MANDEL '2'

# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <time.h>

typedef struct			s_ol
{
	void				*win;
	void				*mlx;
	void				*gda;
	void				*img;
	char				*type;

	int					swinx;
	int					swiny;
	
	int					szl;
	int					endl;
	int					bpx;
	
	int					color;
	int					x1;
	int					x2;
	int					y1;
	int					y2;
	int					decx;
	int					decy;
}						t_ol;

void		find_type(t_ol *stk);
int			main(int argc, char **argv);

void		free_exit(t_ol *stk);
void		argv_error(t_ol *stk);
void		malloc_error(t_ol *stk);

void		julia(t_ol *stk);
void		mandel(t_ol *stk);
void		square(t_ol *stk);

int			event(int code, t_ol *stk);


#endif
