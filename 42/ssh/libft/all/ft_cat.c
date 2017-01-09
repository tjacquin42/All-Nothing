/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 23:39:15 by tjacquin          #+#    #+#             */
/*   Updated: 2015/11/05 23:39:28 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	write(2, str, count);
}

void	print_stdin(void)
{
	char buf;

	while (read(0, &buf, 1) != 0)
		write(1, &buf, 1);
}

void	print_file(int argc, char **argv)
{
	char	buffer;
	int		fd;
	int		i;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd >= 0)
		{
			while (read(fd, &buffer, 1) != 0)
				write(1, &buffer, 1);
		}
		else
		{
			ft_putstr("ft_cat: ");
			ft_putstr(argv[i]);
			ft_putstr(": No such file or directory\n");
		}
		close(fd);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		print_stdin();
	print_file(argc, argv);
}
