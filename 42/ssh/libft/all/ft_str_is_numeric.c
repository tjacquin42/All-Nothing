/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 06:49:54 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/25 06:50:06 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	if (!*str)
		return (1);
	if (*str >= '0' && *str <= '9')
		return (ft_str_is_numeric(str + sizeof(char)));
	return (0);
}
