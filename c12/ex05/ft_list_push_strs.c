/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:00:52 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/04 21:41:22 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*ret;
	t_list	*tmp;
	int		cnt;

	cnt = 0;
	if (size == 0)
		return (NULL);
	ret = ft_create_elem(NULL);
	if (ret == NULL)
		return (NULL);
	while (cnt < size)
	{
		ret->data = *(strs + cnt);
		if (cnt != size - 1)
		{
			tmp = ft_create_elem(NULL);
			if (tmp == NULL)
				return (ret);
			tmp->next = ret;
			ret = tmp;
		}
		cnt++;
	}
	return (ret);
}
