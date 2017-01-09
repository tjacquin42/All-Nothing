/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blo <blo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 19:47:11 by blo               #+#    #+#             */
/*   Updated: 2016/02/11 21:35:34 by blo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 2000000000 
#include "ft.h"

void	ntm(int fd, char *tmp, int k)
{
	char *map;

	while (tmp[k] != '\n')
		k++;
	map = ft_strsub(tmp, k + 1, (ft_strlen(tmp) - k + 1));
	fd = ft_atoi(tmp);
	tmp = ft_strsub(tmp, k - 3, k);
	check(map, fd, tmp);
}

void	mapi(char *str)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		fd;
	int		k;
	int		ret;

	k = 0;
	fd = open(str, O_RDONLY);
	tmp = NULL;
	ret = read(fd, buf, BUFF_SIZE);
	while (ret)
	{
		buf[ret] = '\0';
		if (tmp)
			tmp = ft_strjoin(tmp, buf);
		else
			tmp = ft_strdup(buf);
		ret = read(fd, buf, BUFF_SIZE);
	}
	close(fd);
	ntm(fd, tmp, k);
/*	while (tmp[k] != '\n')
		k++;
	map = ft_strsub(tmp, k + 1, (ft_strlen(tmp) - k + 1));
	fd = ft_atoi(tmp);
	tmp = ft_strsub(tmp, k - 3, k);
	check(map, fd, tmp);*/
}

int		main(int argc, char **argv)
{
	
	if (argc == 2)
		mapi(argv[1]);
	else
		write(1, "map error\n", 10);
	return (0);
}
