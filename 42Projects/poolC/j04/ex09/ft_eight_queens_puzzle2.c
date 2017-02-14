/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 00:37:38 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/27 00:38:31 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		is_ok2(int table[8], int column, int line)
{
	int i;

	i = -1;
	while (++i < column)
		if (line == table[i]
				|| i + table[i] == column + line
				|| i - table[i] == column - line)
			return (0);
	return (1);
}

void	draw(int table[8])
{
	int i;

	i = -1;
	while (++i < 8)
		ft_putchar(table[i] + 49);
	ft_putchar('\n');
}

void	back_track2(int table[8], int pos)
{
	int i;

	if (pos == 8)
		draw(table);
	else
	{
		i = -1;
		while (++i < 8)
			if (is_ok2(table, pos, i))
			{
				table[pos] = i;
				back_track2(table, pos + 1);
			}
	}
}

void	ft_eight_queens_puzzle2(void)
{
	int table[8];
	int i;

	i = -1;
	while (++i < 8)
		table[i] = -1;
	back_track2(table, 0);
}
