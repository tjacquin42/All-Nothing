#include ".././includes/fdf.h"

static int				nbrlen(char *ln)
{
	int		i;
	int		nb;
	int		len;

	len = ft_strlen(ln);
	i = 0;
	nb = 0;
	while (i < len)
	{
		if (ln[i] >= '0' && ln[i] <= '9')
		{
			while (ln[i] != ' ')
				i++;
			nb++;
		}
		else
		{
			while (ln[i] < '0' || ln[i] > '9')
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

static int				*line_atoi(char *buff, int *stck)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	nb = nbrlen(buff);
	stck = (int *)malloc(sizeof(int) * nb + 1);
	while (buff[i])
	{
		if ((buff[i] <= '9' && buff[i] >= '0') || buff[i] == '-')
			stck[j++] = ft_atoi(&buff[i]);
		i = i + next_int_pos(&buff[i]);
	}
	return (stck);
}

static fdf_t			input_use(char *path, fdf_t *stk)
{
	int		ret;
	int		i;
	int		fd;
	char	*buff;

	ret = 1;
	i = -1;
	fd = open(path, O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &buff);
		i++;
	}
	stk->map = (int **)malloc(sizeof(int *) * i);
	fd = open(path, O_RDONLY);
	i = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &buff);
		if (ret == 1)
		{
			stk->map[i] = line_atoi(buff, stk->map[i]);
		}
		i++;
	}
	return (*stk);
}

int						main(int argc, char **argv)
{
	fdf_t	*stk;

	stk = (fdf_t*)malloc(sizeof(fdf_t));
	if (argc == 2)
	{
		*stk = input_use(argv[1], stk);
		get_map(stk);
	}
	else
		ft_putstr("usage: ./fdf [path]\n");
	//stk.mlx = mlx_init();
	//stk.win = mlx_new_window(stk.mlx, 1000, 1000, "FdF");
	//stk.img = mlx_new_image(stk.mlx, 1000, 1000);
	//stk.gda = mlx_get_data_addr(stk.img, &stk.bpx, &stk.szl, &stk.endl);
	//seg_tracer(stk);
	//mlx_put_image_to_window(stk.mlx, stk.win, stk.img, stk.plx, stk.ply);
	//mlx_loop(stk.mlx);
	return 0;
}
