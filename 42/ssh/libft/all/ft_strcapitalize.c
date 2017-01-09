/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 07:13:00 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/26 17:02:37 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		alpha_is_numeric(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = str - 1;
	while (*(++cpy))
	{
		if (!i && *cpy >= 'a' && *cpy <= 'z')
			*cpy = *cpy - 32;
		if (i && *cpy >= 'A' && *cpy <= 'Z')
			*cpy = *cpy + 32;
		if (alpha_is_numeric(*cpy))
			i = 1;
		else
			i = 0;
	}
	return (str);
}
