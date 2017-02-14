/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:43:03 by mnicolas          #+#    #+#             */
/*   Updated: 2016/12/13 22:42:03 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# define BUFF_SIZE 32

typedef	struct		s_fd
{
	int				fd;
	char			*text;
	struct s_fd		*next;
	struct s_fd		*begin_list;
}					t_fd;

int					get_next_line(int const fd, char **dest);

#endif
