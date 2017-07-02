/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:32:35 by tjacquin          #+#    #+#             */
/*   Updated: 2017/05/23 15:37:31 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void			init(t_wo *stk)
{
	if (!(stk->bird = (t_brd*)malloc(sizeof(t_brd))))
		exit (0);
	stk->bird->i = 0;
	stk->bird->j = 0;
	stk->bird->dec_x = 0;
	stk->bird->dec_y = 0;
	stk->bird->x = 0;
	stk->bird->y = 0;
	stk->co = 10;

	stk->swin = 642;
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, stk->swin, stk->swin, "Bird_View");
	stk->img = mlx_new_image(stk->mlx, stk->swin, stk->swin);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	stk->color = 16777215;
	stk->rot_y = 0;
	stk->rot_x = 0;
	stk->mv_x = 5;
	stk->mv_y = 5;
	map_trace(stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_hook(stk->win, 2, 3, event, stk);
	mlx_loop(stk->mlx);
}

static void		ft_put_2d_str(char **map, char *buf, int i)
{
	int j;
	int a;

	j = 0;
	a = 0;
		while (j < 10)
		{
			if (buf[a] == ' ')
			{
				a++;
			}
			map[i][j] = buf[a];
			j++;
			a++;
		}
}

static int		input(char *path, t_wo *stk)
{
	int		ret;
	int		i;
	int		fd;
	char	*buf;

	fd = open(path, O_RDONLY);
	ret = 1;
	i = 0;
	if (!(stk->map = (char **)malloc(sizeof(char *) * stk->size_map)))
		return (0);
	while (i < stk->size_map)
	{
		if (!(stk->map[i++] = (char *)malloc(sizeof(char) * stk->size_map)))
			return (0);
	}
	i = 0;
	while (i < stk->size_map)
	{
		ret = get_next_line(fd, &buf);
		ft_put_2d_str(stk->map, buf, i);
		i++;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_wo *stk;

	if (!(stk = (t_wo*)malloc(sizeof(t_wo))))
		return (0);
	stk->size_map = 10;
	stk->size_box = 64;
	if (argc == 2)
	{
		input(argv[1], stk);
		init(stk);
	}
	return (0);
}
