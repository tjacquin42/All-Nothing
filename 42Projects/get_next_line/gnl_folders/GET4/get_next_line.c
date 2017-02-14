/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 22:01:29 by tjacquin          #+#    #+#             */
/*   Updated: 2017/01/20 14:38:59 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line(char *buff)
{
	char	*one;
	int		i;
	int		a;

	i = 0;
	a = 0;
	one = (char*)malloc(sizeof(char*) * ft_strlen(buff));
	while (buff[i] != '\0')
	{
		one[a] = buff[i];
		a++;
		i++;
		ft_putchar(one[a]);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE];
	int				num;
	static t_fd		*current = NULL;

	num = read(fd, buff, BUFF_SIZE);
	buff[num] = '\0';
	get_line(buff);
	return (0);
}
