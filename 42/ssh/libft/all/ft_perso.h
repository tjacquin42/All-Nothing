/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 03:43:13 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/23 13:18:58 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H

# include <string.h>

# define SAVE_AUSTIN_POWERS 31415

typedef struct	s_perso
{
	char		*name;
	int			life;
	int			age;
	int			profession;
}				t_perso;

#endif
