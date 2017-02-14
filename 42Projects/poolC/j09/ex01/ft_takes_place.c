/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 17:18:53 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/22 17:27:01 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	if (hour <= 24)
	{
		printf("THE FOLLOWING TAKES PLACE BETWEEN ");
		if (hour <= 10 && hour != 0)
			printf("%d.00 A.M. AND %d.00 A.M.\n", hour, hour + 1);
		else if (hour == 11)
			printf("11.00 A.M. AND 12.00 P.M.\n");
		else if (hour == 12)
			printf("12.00 P.M. AND 1.00 P.M.\n");
		else if (hour == 23)
			printf("11.00 P.M. AND 12.00 A.M.\n");
		else if (hour == 24 || hour == 0)
			printf("12.00 A.M. AND 1.00 A.M.\n");
		else
			printf("%d.00 P.M. AND %d.00 P.M.\n", hour - 12, hour - 11);
	}
}
