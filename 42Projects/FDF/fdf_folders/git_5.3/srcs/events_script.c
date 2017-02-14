/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_script.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:37:19 by ghubert           #+#    #+#             */
/*   Updated: 2017/02/01 16:21:57 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

fdf_t				*map_walker(fdf_t *stk, int y, int fd)
{
	int		nb;
	int		nb2 = 1;
	int		x;
	char	*line;
	int		ret;
	
	while (y < stk->ln)
	{
		x = 0;
		ret = get_next_line(fd, &line);
		if (!nb)
		{
			nb = nbrlen(line);
			get_next_line(fd, &line);
		}
		if (ret == 1)
			nb2 = nbrlen(line);
		stk = print_squares(nb, nb2, x, y, stk);
		nb = nb2;
		nb2++;
		y++;
	}
	return (stk);
}

fdf_t				*pixel_push(fdf_t *stk)
{
	int		ret;
	int		fd;
	char	*line;

	fd = open(stk->path, O_RDONLY);
	ret = get_next_line(fd, &line);
	if (ret == 1)
		stk->ln = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		stk->ln++;
	}
	free(line);
	fd = open(stk->path, O_RDONLY);
	stk = map_walker(stk, ret, fd);
	return (stk);
}

fdf_t				*print_img(fdf_t *stk)
{
	/*if (stk->img)
		mlx_destroy_image(stk->mlx, stk->img);*/
	stk->img = mlx_new_image(stk->mlx, 1000, 1000);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	stk = pixel_push(stk);
	mlx_clear_window(stk->mlx, stk->win);
	//mlx_put_image_to_window(stk->mlx, stk->win, stk->img, stk->plx, stk->ply);
	return (stk);
}

static fdf_t		*img_rot(int keycode, fdf_t *stk)
{
	if (keycode == 53)
	{
		ft_memdel((void **)stk->mlx);
		ft_memdel((void **)stk->win);
		ft_memdel((void **)&stk);
		exit (0);
	}
	if (keycode == 126)
		stk->x_d += 10;
	else if (keycode == 125)
		stk->x_d -= 10;
	else if (keycode == 123)
		stk->z_d -= 10;
	else if (keycode == 124)
		stk->z_d += 10;
	ft_putnbr(keycode);
	ft_putchar('\n');
	stk = print_img(stk);
	return (stk);
}

static int		expose(fdf_t *stk)
{
	print_img(stk);
	return (0);
}

int				img_gen(int keycode, fdf_t *stk)
{
	if (keycode == 0)
		stk = print_img(stk);
	else if (keycode)
		stk = img_rot(keycode, stk);
	mlx_key_hook(stk->win, img_gen, stk);
	mlx_expose_hook(stk->win, expose, stk);
	mlx_loop(stk->mlx);
	return (0);
}
