/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:06:27 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/04 23:00:36 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*ptr1;
	t_list	*ptr2;
	void	*swpdata;

	ptr1 = (*begin_list);
	ptr2 = (*begin_list);
	if (ptr1 == NULL)
		return ;
	while (ptr1 != NULL)
	{
		while (ptr2 != NULL)
		{
			if (cmp(ptr1->data, ptr2->data) > 0)
			{
				swpdata = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = swpdata;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr1;
	}
}
