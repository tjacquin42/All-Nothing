/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckupfers <ckupfers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 14:11:43 by ckupfers          #+#    #+#             */
/*   Updated: 2015/12/20 20:07:46 by ckupfers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	putstr_stdout(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	write(2, str, count);
}

void	aff_contenu(int ac, char **av)
{
	char	c;
	int		file_d;
	int		p;

	p = 0;
	while (++p < ac)
	{
		file_d = open(av[p], O_RDONLY);
		if (file_d >= 0)
		{
			while (read(file_d, &c, 1) != 0)
				write(1, &c, 1);
		}
		else
		{
			putstr_stdout("cat: ");
			putstr_stdout(av[p]);
			putstr_stdout(": No such file or directory\n");
		}
		close(file_d);
	}
}

int		main(int ac, char **av)
{
	char c;

	if (ac < 2)
	{
		while (read(0, &c, 1) != 0)
			write(1, &c, 1);
	}
	aff_contenu(ac, av);
	return (0);
}
