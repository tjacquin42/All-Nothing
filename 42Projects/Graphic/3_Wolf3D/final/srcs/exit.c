/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:50:20 by tjacquin          #+#    #+#             */
/*   Updated: 2017/06/12 19:21:25 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int		exit_redcross(t_all *truc)
{
	free(truc->map);
	free(truc);
	system("killall afplay");
	exit(0);
	return (0);
}

int		echap_key(t_all *truc)
{
	free(truc->map);
	free(truc);
	system("killall afplay");
	exit(0);
	return (0);
}
