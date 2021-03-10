/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:23:46 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/02 19:25:51 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *ret;
	int cnt;

	cnt = 0;
	ret = (int *)malloc(sizeof(int) * length);
	while (cnt < length)
	{
		*(ret + cnt) = f(*(tab + cnt));
		cnt++;
	}
	return (ret);
}
