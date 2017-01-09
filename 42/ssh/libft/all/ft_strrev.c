/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 01:31:11 by tjacquin          #+#    #+#             */
/*   Updated: 2015/11/08 19:18:10 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	rev;
	int		count;
	int		beg;
	int		div;

	beg = 0;
	count = 0;
	if (str)
	{
		while (str[count] != '\0')
		{
			count++;
		}
		count--;
		div = count / 2;
		while (div != count)
		{
			rev = str[count];
			str[count] = str[beg];
			str[beg] = rev;
			beg++;
			count--;
		}
	}
	return (str);
}
