/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:32:43 by tjacquin          #+#    #+#             */
/*   Updated: 2016/12/13 22:59:55 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.next.line/get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char **line;
	const int	fd = open(argv[1], O_RDONLY);

	if	(argc == 2)
	{
		printf("%d", get_next_line(fd, line));
		printf("%d", get_next_line(fd, line));
		printf("%d", get_next_line(fd, line));
		printf("%d", get_next_line(fd, line));
		printf("%d", get_next_line(fd, line));
		printf("%d", get_next_line(fd, line));
		printf("%d", get_next_line(fd, line));
	}
	return (0);
}
