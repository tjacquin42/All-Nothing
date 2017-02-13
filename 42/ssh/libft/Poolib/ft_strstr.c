/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 13:31:36 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/27 13:31:43 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *ans;
	char *tmp;
	char *aim;

	if (!*to_find)
		return (str);
	tmp = str;
	while (*tmp)
	{
		ans = tmp;
		aim = to_find;
		while (*tmp && *aim && *tmp == *aim)
		{
			++tmp;
			++aim;
		}
		if (!*aim)
			return (ans);
		tmp = ans + 1;
	}
	return (0);
}
