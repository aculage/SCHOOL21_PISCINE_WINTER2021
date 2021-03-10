/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:02:00 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/04 21:02:00 by hbrendon         ###   ########.fr       */
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
