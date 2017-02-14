#include <unistd.h> 

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*void	cross(char *tab, int o, char save, int x, char tall)
{
	char tall2;
	int save2;
	
	tall2 = tall;
	save2 = save; 
	while (tall2 > '0')
	{
		tab[save / x + 1] = 'x';
		while (tall2 > '0')
		{
			tab[save2--] = 'x';
			tall2--;
		}
	}
}
*/

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
	o = 0;
	while (tab[o] != '\0')
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

int main(void)
{
	char tab[] = "ooo\nooo\nooo\n";
	int i = 3;

	check(tab, i);
	return (0);
}
