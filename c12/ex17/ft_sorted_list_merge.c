/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:09:24 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/04 22:02:44 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1,
t_list *begin_list2, int (*cmp)())
{
	t_list	*nextr;
	t_list	*lcl;

	lcl = *begin_list1;
	if (lcl == NULL)
	{
		(lcl)->next = begin_list2;
		return ;
	}
	if (begin_list2 == NULL)
		return ;
	while ((lcl)->next != NULL && begin_list2 != NULL)
	{
		if (cmp((lcl)->next->data, (begin_list2)->data) > 0)
		{
			nextr = (lcl)->next;
			(lcl)->next = (begin_list2);
			begin_list2 = begin_list2->next;
			(lcl)->next->next = nextr;
			(lcl) = (lcl)->next;
		}
	}
	if ((lcl)->next == NULL)
		(lcl)->next = begin_list2;
	return ;
}
