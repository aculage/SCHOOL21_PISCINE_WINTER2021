/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:24:29 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/02 19:25:04 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int cnt;
	int flag;

	flag = 0;
	cnt = 1;
	while (cnt < length)
	{
		if (f(*(tab + cnt - 1), *(tab + cnt)) > 0)
		{
			if (flag == 2)
				return (0);
			flag = 1;
		}
		if (f(*(tab + cnt - 1), *(tab + cnt)) < 0)
		{
			if (flag == 1)
				return (0);
			flag = 2;
		}
		cnt++;
	}
	return (1);
}
