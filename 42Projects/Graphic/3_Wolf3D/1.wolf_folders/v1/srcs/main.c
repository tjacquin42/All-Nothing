/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:32:35 by tjacquin          #+#    #+#             */
/*   Updated: 2017/05/10 17:34:27 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void			init(t_wo *stk)
{
	stk->swin = 500;
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, stk->swin, stk->swin, "Bird_View");
	stk->img = mlx_new_image(stk->mlx, stk->swin, stk->swin);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	stk->color = 16777215;

	parce_map(stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
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
			ft_putchar(map[i][j]);
			j++;
			a++;
		}
		ft_putchar('\n');
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
	if (!(stk->map = (char **)malloc(sizeof(char *) * 10)))
		return (0);
	while (i < 10)
	{
		if (!(stk->map[i++] = (char *)malloc(sizeof(char) * 10)))
			return (0);
	}
	i = 0;
	while (i < 10)
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
	if (argc == 2)
	{
		input(argv[1], stk);
		init(stk);
	}
	return (0);
}
