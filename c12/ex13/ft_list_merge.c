/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:46:21 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/04 22:30:04 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*lcl;

	if (*begin_list1 == NULL)
	{
		(*begin_list1) = begin_list2;
		return ;
	}
	lcl = *begin_list1;
	while ((lcl)->next != NULL)
		(lcl) = (lcl)->next;
	(lcl)->next = begin_list2;
}
