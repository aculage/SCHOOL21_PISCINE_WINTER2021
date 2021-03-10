/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:11:24 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/05 23:07:40 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root, void *data_ref,
int (*cmpf)(void *, void *))
{
	void *fnd;

	if (root == NULL)
		return (NULL);
	fnd = btree_search_item((root)->left, data_ref, cmpf);
	if (fnd != NULL)
		return (fnd);
	if (cmpf((root)->item, data_ref) == 0)
	{
		return ((root)->item);
	}
	fnd = btree_search_item((root)->right, data_ref, cmpf);
	if (fnd != NULL)
		return (fnd);
	return (NULL);
}
