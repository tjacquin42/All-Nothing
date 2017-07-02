/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:04:18 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/09 19:25:10 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int						nbrlen(char *ln)
{
	int		i;
	int		nb;
	int		len;

	if (!ln)
		return (0);
	len = ft_strlen(ln);
	i = 0;
	nb = 0;
	while (i < len && ln[i] != '\0')
	{
		if (ln[i] >= '0' && ln[i] <= '9' && ln[i] != '\0')
		{
			while (ln[i] != ' ' && ln[i] != '\0')
				i++;
			nb++;
		}
		else
		{
			while ((ln[i] < '0' || ln[i] > '9') && ln[i] != '\0')
				i++;
		}
	}
	return (nb);
}

static int				next_int_pos(char *buff)
{
	int		i;

	i = 0;
	while (buff[i] != ' ' && buff[i])
		i++;
	while (buff[i] == ' ' && buff[i])
		i++;
	return (i);
}

static int				*line_atoi(char *buff, int *stck, int xmax)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(stck = (int *)malloc(sizeof(int) * xmax)))
		malloc_error((int *)stck);
	while (buff[i])
	{
		if ((buff[i] <= '9' && buff[i] >= '0') || buff[i] == '-')
			stck[j++] = ft_atoi(&buff[i]);
		i = i + next_int_pos(&buff[i]);
	}
	return (stck);
}

static void				input_use(char *path, t_fdf *stk)
{
	int		ret;
	int		i;
	int		fd;
	char	*buff;

	fd = open(path, O_RDONLY);
	ret = get_next_line(fd, &buff);
	stk->xmax = nbrlen(buff);
	stk->ymax = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, &buff);
		stk->ymax++;
	}
	if (!(stk->map = (int **)malloc(sizeof(int *) * stk->ymax)))
		malloc_error((t_fdf *)stk);
	fd = open(path, O_RDONLY);
	i = 0;
	ret = stk->ymax;
	while (ret-- != 0)
	{
		get_next_line(fd, &buff);
		stk->map[i] = line_atoi(buff, stk->map[i], stk->xmax);
		i++;
	}
}

int						main(int argc, char **argv)
{
	t_fdf	*stk;

	if (!(stk = (t_fdf *)malloc(sizeof(t_fdf))))
		malloc_error((t_fdf *)stk);
	if (argc > 2 || argc < 2)
		((argc > 2) ? argv_error(2) : argv_error(1));
	input_use(argv[1], stk);
	init(stk);
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, stk->size_win, stk->size_win, "FdF");
	stk->img = mlx_new_image(stk->mlx, stk->size_win, stk->size_win);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	map_trace(stk);
	display();
	mlx_hook(stk->win, 2, 3, event, stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);
	return (0);
}
