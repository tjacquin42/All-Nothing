/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:12:12 by tjacquin          #+#    #+#             */
/*   Updated: 2017/01/18 17:20:13 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int	filline(int j, char **save, char **line)
{
	int i;
	int y;

	y = 0;
	i = 0;
	if (j != 0 || ft_strlen((*save)) != 0)
	{
		while ((*save)[i] != '\n')
		{
			(*line)[i] = (*save)[i];
			i++;
		}
		(*line)[i++] = '\0';
		if ((*save)[0] == '\n')
		{
			while ((*save)[i])
				(*save)[y++] = (*save)[i++];
			(*save)[y] = '\0';
			return (2);
		}
		while ((*save)[i])
			(*save)[y++] = (*save)[i++];
		(*save)[y] = '\0';
	}
	return (1);
}

int	mallagain(char **save)
{
	char *tmp;

	if (!(tmp = ft_strnew(ft_strlen(*save))))
		return (0);
	ft_strcpy(tmp, *save);
	*save = NULL;
	if (!(*save = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return (0);
	ft_strcpy(*save, tmp);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int			j;
	static char *save;

	if ((fd < 0 || fd == 1 || fd == 2) ||
			(!save && !(save = ft_strnew(BUFF_SIZE))))
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	while ((j = read(fd, *line, BUFF_SIZE)) > 0)
	{
		if (!(mallagain(&save)))
			return (-1);
		ft_strncat(save, *line, BUFF_SIZE);
		if (ft_memchr(*line, '\n', BUFF_SIZE))
			break ;
	}
	if ((filline(j, &save, &(*line))) == 2)
		return (1);
	if (ft_memcmp((*line), save, ft_strlen(*line)) == 0)
	{
		if (!(*line = ft_strdup("")))
			return (1);
		return (0);
	}
	return ((*line) ? 1 : 0);
}
