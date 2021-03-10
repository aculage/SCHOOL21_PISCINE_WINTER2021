/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:02:18 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/04 20:56:23 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	ret->data = data;
	ret->next = NULL;
	return (ret);
}
