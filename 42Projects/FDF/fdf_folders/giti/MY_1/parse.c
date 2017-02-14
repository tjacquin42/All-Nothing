/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:57:48 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/02 19:08:32 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			*input_use(fdf_t stk)
{
	int		ret;
	int		i;
	int		fd;
	char	*buf;

	fd = open(stk->path, O_RDONLY);
	ret = 1;
	i = -1;
	if (!(stk->map = (int **)malloc(sizeoff(int *) * i))
			malloc_error();
	fd = open(stk->path, O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &buf);
		{

		}
	}
}
