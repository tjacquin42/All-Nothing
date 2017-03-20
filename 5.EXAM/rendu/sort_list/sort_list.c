/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:31:42 by tjacquin          #+#    #+#             */
/*   Updated: 2017/03/14 17:41:38 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *count;
	t_list *current;
	int l;
	int temp;
	
	count = lst;
	while(count)
	{
		count = count->next;
		l++;
	}
	current = lst;
	while (l)
	{
		while(current->next)
		{
			if ((cmp)(current->data, current->next->data))
			{
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
			}
			current = current->next;
		}
		l--;
		current = lst;
	}
	return (current);
}
