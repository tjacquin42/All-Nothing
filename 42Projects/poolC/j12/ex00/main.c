/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 20:01:23 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/02 20:02:01 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	affich_contenu(int file_d)
{
	char c;

	while (read(file_d, &c, 1) != 0)
		write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int file_d;

	if (ac != 2)
	{
		if (ac > 2)
			write(2, "Too many arguments.\n", 20);
		if (ac < 2)
			write(2, "File name missing.\n", 19);
		return (1);
	}
	file_d = open(av[1], O_RDONLY);
	affich_contenu(file_d);
	close(file_d);
	return (0);
}
