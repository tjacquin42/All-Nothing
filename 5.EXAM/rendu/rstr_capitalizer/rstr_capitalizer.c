/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:13:20 by tjacquin          #+#    #+#             */
/*   Updated: 2017/03/15 14:51:52 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

char	*verif(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z'
				&& str[i + 1] != ' ' && str[i + 1] != '\t'
				&& str[i + 1] != '\0')
			str[i] += 32;
		if (str[i] >= 'a' && str[i] <= 'z' &&
				(str[i + 1] == ' ' || str[i + 1] == '\t' ||
				 str[i + 1] == '\0'))
				str[i] -= 32;
		i++;
	}
	return (str);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			ft_putstr(verif(argv[i]));
			ft_putstr("\n");
			i++;
		}
	}
	else
		ft_putstr("\n");
	return (0);
}
