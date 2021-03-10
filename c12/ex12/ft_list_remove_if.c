/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:05:25 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/04 23:32:47 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
int (*cmp)(), void (*free_fct)(void *))
{
	t_list *swp;
	t_list *lcl;

	lcl = *begin_list;
	if (lcl == NULL)
		return ;
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		free_fct((*begin_list)->data);
		swp = (*begin_list)->next;
		free((*begin_list));
		(*begin_list) = swp;
		return ;
	}
	while ((lcl)->next != NULL)
		if (cmp((lcl)->next->data, data_ref) == 0)
		{
			free_fct(lcl->next->data);
			swp = lcl->next->next;
			free(lcl->next);
			lcl->next = swp;
		}
		else
			lcl = lcl->next;
}
