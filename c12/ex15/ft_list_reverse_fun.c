/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:06:48 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/04 21:45:32 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int cnt;

	cnt = 0;
	while (cnt < nbr)
	{
		if (begin_list == NULL)
			return (NULL);
		begin_list = begin_list->next;
		cnt++;
	}
	return (begin_list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	t_list	*swp1;
	int		cnt;
	void	*swp;

	cnt = 0;
	swp1 = begin_list;
	size = 0;
	while (swp1 != NULL)
	{
		size++;
		swp1 = swp1->next;
	}
	while (cnt < size / 2)
	{
		swp = ft_list_at(begin_list, cnt)->data;
		ft_list_at(begin_list, cnt)->data =
		ft_list_at(begin_list, size - cnt - 1)->data;
		ft_list_at(begin_list, size - cnt - 1)->data = swp;
		cnt++;
	}
}
