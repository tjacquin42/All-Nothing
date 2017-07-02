#include <unistd.h> 
#include <stdio.h> 
#include "get_next_line.h" 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define TEST write(1, "test\n", 5);
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}*/

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

void	cross(char *tab, char tall, int x, int save)
{
	int carre;
	int mem;
	int suce;

	carre = tall - 48;
	mem = carre;
	suce = carre;
	while (save >= 0 && suce > 0)
	{
		while (carre > 0)
		{
			tab[save] = 'x';
			carre--;
			save--;
		}
		save = save - x + mem;
		carre = mem;
		save--;
		suce--;
	}
}

void	final(char *tab, char tall, int x, int o)
{
	int save;

	save = 0;
	while (tab[o] != tall)
		o++;
	save = o;
	o = 0;
	while ((x * x + x) != o)
	{
		if (tab[o] == '0')
			tab[o] = 'o';
		else if (tab[o] != '\n')
			tab[o] = '.';
		o++;
	}
	cross(tab, tall, x, save);

	{
		ft_putchar(tab[o]);
		o++;
	}

}

char	superior(char left, char up, char diag)
{
	char sup;

	sup = left;
	if (sup > up)
		sup = up;
	if (sup > diag)
		sup = diag;
	return (sup + 1);
}

void	check(char *tab, int x)
{
	int o;
	char tall;

	o = 0;
	tall = 0;
	while ((x * x + x) != o)
	{
		if (o < x && tab[o] != 'o')
			tab[o] = '1';
		else if ((tab[o] == '\n') && tab[o + 1] != 'o' && tab[o + 1] != '\0')
			tab[o + 1] = '1';
		else if (tab[o] == 'o')
			tab[o] = '0';
		else if (tab[o] == '.')
			tab[o] = superior(tab[o - 1], tab[o - x - 1], tab[o - x - 2]);
		if (tall < tab[o])
			tall = tab[o];
		o++;
	}
	o = 0;
	final(tab, tall, x, o);
}

int main(int argc, char **argv)
{
	char	buf[130];
	char	*map;
//	int 	i = 0;
	int		fd;
	int		k = 0;
	int		ret;

	if (argc != 2)
	{
		ft_putstr("Only one argument\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, 129);
	buf[ret] = '\0';
//	ft_putstr(buf);
	while (buf[k] != '\n')
		k++;
	map = ft_strsub(buf, k + 1, (ft_strlen(buf) - k + 1));
//	ft_putstr(map);
	check(map, 10);
	return (0);
}
