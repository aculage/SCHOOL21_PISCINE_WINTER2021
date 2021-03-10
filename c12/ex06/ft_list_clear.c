/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:19:47 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/03 16:20:04 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *next;

	next = begin_list;
	while (begin_list != NULL)
	{
		next = begin_list->next;
		free_fct(begin_list->data);
		free(begin_list);
		begin_list = next;
	}
}
