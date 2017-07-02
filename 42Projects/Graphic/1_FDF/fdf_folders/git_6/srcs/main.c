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
	stck = (int *)malloc(sizeof(int) * xmax);
	while (buff[i])
	{
		if ((buff[i] <= '9' && buff[i] >= '0') || buff[i] == '-')
			stck[j++] = ft_atoi(&buff[i]);
		i = i + next_int_pos(&buff[i]);
	}
	return (stck);
}

static void				input_use(char *path, fdf_t *stk)
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
	stk->map = (int **)malloc(sizeof(int *) * stk->ymax);
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
	fdf_t	*stk;

	stk = (fdf_t *)malloc(sizeof(fdf_t));
	if (argc == 2)
		input_use(argv[1], stk);
 	stk->rx = 0;
	stk->ry = 0;
	stk->rz = 0;
	stk->size_win = 1000;   //SIZE WINDOW
	stk->decal_x = 0;
	stk->decal_y = 0;
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, stk->size_win, stk->size_win, "FdF");
	stk->img = mlx_new_image(stk->mlx, stk->size_win, stk->size_win); //SIZE WINDOW
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	map_trace(stk);
	display(); // DISPLAY CONTROLS
	mlx_key_hook(stk->win, img_gen, stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);
	return (0);
}
