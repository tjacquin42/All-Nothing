/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 20:50:53 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/20 21:11:20 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int	race;

	race = 1;
	if (nb <= 0 || nb == 2)
		return (0);
	while (race * race < nb)
		race++;
	if ((nb % race) == 0)
		return (race);
	else
		return (0);
}
