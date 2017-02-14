/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:12:39 by tjacquin          #+#    #+#             */
/*   Updated: 2017/01/20 15:22:56 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 180
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int get_next_line(const int fd, char **line);

#endif
