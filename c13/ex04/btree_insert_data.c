/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:11:24 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/05 23:00:43 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	btree_insert_data(t_btree **root, void *item,
int (*cmpf)(void *, void *))
{
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf((*root)->item, item) <= 0)
	{
		if ((*root)->right == NULL)
		{
			(*root)->right = btree_create_node(item);
			return ;
		}
		else
			btree_insert_data(&((*root)->right), item, cmpf);
	}
	else
	{
		if ((*root)->left == NULL)
		{
			(*root)->left = btree_create_node(item);
			return ;
		}
		else
			btree_insert_data(&((*root)->left), item, cmpf);
	}
}
