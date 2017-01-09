/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:32:43 by tjacquin          #+#    #+#             */
/*   Updated: 2017/01/06 19:05:24 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char **line;
	const int	fd = open(argv[1], O_RDONLY);
	int ret = 0;
	
	get_next_line(fd, line);
	printf("%s, line");
	printf("%d, fd");
	get_next_line(fd, line);
	printf("%s, line");
	printf("%d, fd");

	return (0);
}
