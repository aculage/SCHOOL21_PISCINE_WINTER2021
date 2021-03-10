/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:01:48 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/05 23:02:38 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

int	btree_level_count(t_btree *root)
{
	int ldepth;
	int rdepth;

	if (root == NULL)
		return (0);
	ldepth = btree_level_count(root->left);
	rdepth = btree_level_count(root->right);
	if (rdepth > ldepth)
		return (rdepth + 1);
	else
		return (ldepth + 1);
}
