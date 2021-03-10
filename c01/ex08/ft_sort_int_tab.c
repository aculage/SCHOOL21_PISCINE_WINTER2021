/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:34:57 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/18 17:28:04 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int a;
	int s;

	a = 0;
	s = size;
	while (a < size * size)
	{
		if ((tab[a % s] > tab[(a + 1) % s]) && (a % s < (a + 1) % s))
		{
			ft_swap(&tab[a % s], &tab[(a + 1) % s]);
		}
		a++;
	}
}
