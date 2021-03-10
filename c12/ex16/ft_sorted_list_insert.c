/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:09:19 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/04 22:01:21 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*s;
	t_list	*lcl;

	lcl = *begin_list;
	if (lcl == NULL)
		return ;
	while (((lcl)->next) != NULL)
	{
		if (cmp((lcl)->next->data, data) > 0)
		{
			s = (lcl)->next;
			(lcl)->next = ft_create_elem(data);
			(lcl)->next->next = s;
		}
		(lcl) = (lcl)->next;
	}
}
