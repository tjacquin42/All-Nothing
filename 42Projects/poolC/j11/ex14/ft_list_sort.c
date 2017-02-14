/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 19:40:51 by tjacquin          #+#    #+#             */
/*   Updated: 2015/11/06 16:47:34 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

static void		ft_swap(t_list **elem1, t_list **elem2)
{
	void		*tmp_data;

	tmp_data = (*elem1)->data;
	(*elem1)->data = (*elem2)->data;
	(*elem2)->data = tmp_data;
}

void			ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list		*tmp1;
	t_list		*tmp2;
	int			sorted;

	sorted = 1;
	if (*begin_list == NULL || (*begin_list)->next == NULL)
		return ;
	while (sorted)
	{
		sorted = 0;
		tmp1 = *begin_list;
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if ((*cmp)(tmp1->data, tmp2->data) > 0)
			{
				ft_swap(&tmp1, &tmp2);
				sorted = 1;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp1->next;
		}
	}
}
