/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:02:18 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/07 13:52:48 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*next;
	t_list	*prev;

	prev = NULL;
	while (*begin_list != NULL)
	{
		next = (*begin_list)->next;
		(*begin_list)->next = prev;
		prev = *begin_list;
		if (next != NULL)
			*begin_list = next;
		else
			return ;
	}
}
