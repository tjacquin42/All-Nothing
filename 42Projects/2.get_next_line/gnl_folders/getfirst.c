/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 22:01:29 by tjacquin          #+#    #+#             */
/*   Updated: 2016/09/05 20:50:26 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_line(char **line, int len)
{
	static int I = 0;
	static int i = -1;
	int a;
	char *save;
	
	a = -1;
	save = ft_memalloc(len);
	while (line[I][i] != '\n')
	{
		save[a++] = line[I][i++];
	}
	i++;
	return (save);
}

int		get_next_line(const int fd, char **line)
{
	int		ride;
	const int		fd_bis;

	//line = ft_memalloc(BUFF_SIZE + 1);
	if (fd)
	{
		ride = read(fd, line, BUFF_SIZE);
		return (read_line(line, ride));
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	line[BUFF_SIZE + 1];

	line = ft_memalloc
	if (argc == 2)
	{
		get_next_line(fd, line); 
	}
	else
		return (0);
}
