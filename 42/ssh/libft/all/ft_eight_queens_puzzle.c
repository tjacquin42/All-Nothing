/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 00:36:22 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/27 00:36:24 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_ok(int table[8], int column, int line)
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

void	back_track(int table[8], int *ans, int pos)
{
	int i;

	if (pos == 8)
		*ans = 1 + *ans;
	else
	{
		i = -1;
		while (++i < 8)
			if (is_ok(table, pos, i))
			{
				table[pos] = i;
				back_track(table, ans, pos + 1);
			}
	}
}

int		ft_eight_queens_puzzle(void)
{
	int table[8];
	int i;
	int ans;

	i = -1;
	while (++i < 8)
		table[i] = -1;
	ans = 0;
	back_track(table, &ans, 0);
	return (ans);
}
