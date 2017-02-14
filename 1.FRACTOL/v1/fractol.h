/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 00:59:36 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/13 10:57:01 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define JULIA 1
# define MANDEL 2

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
	int					szl;
	int					endl;
	int					bpx;

}						t_ol;

int			main(int argc, char **argv);
void		argv_error(t_ol *stk);
void		malloc_error(t_ol *stk);
void		init(int frac, t_ol *stk);
#endif
