/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:44:25 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/05 22:57:11 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*ret;

	ret = malloc(sizeof(t_btree));
	if (ret == NULL)
		return (ret);
	ret->left = NULL;
	ret->right = NULL;
	ret->item = item;
	return (ret);
}
