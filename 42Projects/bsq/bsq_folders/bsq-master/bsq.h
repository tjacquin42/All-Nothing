/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 15:57:24 by mnicolas          #+#    #+#             */
/*   Updated: 2016/02/04 16:04:45 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct	s_bsq
{
	int		lines;
	char	full;
	char	empty;
	char	obst;
}				t_bsq;

void	get_chars(char *map);
{
	int		i;
	int		line;
	char *lines;
	t_bsq	nique;

	i = 0;
	ine = 0;
	while (ft_isdigit(map[i]))
		i++;
	line = ft_strsub(map, 0, i); 
	nique.empty = map[i];
	nique.obst = map[i + 1];
	nique.empty = map[i + 2];
	

}

#endif
