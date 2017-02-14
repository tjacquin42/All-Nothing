/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 22:01:29 by tjacquin          #+#    #+#             */
/*   Updated: 2017/01/06 16:23:40 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*strfreejoin(char *str, char *buf, int lib)
{
	char	*temp;

	temp = ft_strjoin(str, buf);
	if (str && (lib == 3 || lib == 2))
	{
		free(str);
		str = NULL;
	}
	if (buf && (lib == 3 || lib == 1))
	{
		free(buf);
		buf = NULL;
	}
	return (temp);
}

static int		read_fd(int fd, char *buffer)
{
	int ret;

	ret = read(fd, buffer, BUFF_SIZE);
	if (ret != -1)
		buffer[ret] = '\0';
	return (ret);
}

static	size_t	ft_check_endofline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		++i;
	}
	return (0);
}

static t_fd		*get_fd(t_fd *current, int fd)
{
	t_fd	*temp;

	temp = current;
	if (temp)
	{
		while (temp->next)
		{
			if (temp->fd == fd)
				return (temp);
			temp = temp->next;
		}
		if (temp->fd == fd)
			return (temp);
		if (!(temp->next = (t_fd *)malloc(sizeof(t_fd))))
			return (NULL);
		temp = temp->next;
	}
	else if (!(temp = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	temp->fd = fd;
	temp->text = ft_strdup("");
	temp->next = NULL;
	temp->begin_list = (!current) ? temp : current;
	return (temp);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*current_fd = NULL;
	char			buffer[BUFF_SIZE];
	char			*linebis;
	int				len;
	int				reader;

	reader = 0;
	current_fd = get_fd(current_fd, fd);
	if ((fd < 0 || fd == 1 || fd == 2) || line == NULL)
		return (-1);
	while (fd >= 0 && ((len = ft_check_endofline(current_fd->text)) ||
				(reader = read_fd(fd, buffer)) > 0) && len <= 0)
		current_fd->text = strfreejoin(current_fd->text, buffer, 2);
	if (reader == -1)
		return (-1);
	if (len > 0)
		current_fd->text[len - 1] = '\0';
	*line = ft_strdup(current_fd->text);
	linebis = current_fd->text;
	current_fd->text = ((len > 0) ? ft_strdup(current_fd->text + len) :
			ft_strdup(""));
	free(linebis);
	current_fd = current_fd->begin_list;
	return ((len || **line) ? 1 : 0);
}
