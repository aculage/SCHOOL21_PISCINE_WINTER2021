/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 22:54:00 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/17 22:54:03 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	warr(char *num, int n, char flag)
{
	char	z;
	int		i;

	z = 48;
	i = 0;
	while (i < n)
	{
		z += num[i];
		write(1, &z, 1);
		i++;
		z = 48;
	}
	if (flag == 0)
	{
		write(1, ", ", 2);
	}
}

void	rec(char *num, int st_depth, int cur_depth, int n)
{
	while ((cur_depth <= 10 - n + st_depth) && (st_depth <= 9))
	{
		num[st_depth] = cur_depth;
		cur_depth++;
		rec(num, st_depth + 1, cur_depth, n);
		if (10 - n + st_depth == 9)
		{
			if (num[0] == 10 - n)
			{
				warr(num, n, 1);
			}
			else
			{
				warr(num, n, 0);
			}
		}
	}
}

void	ft_print_combn(int n)
{
	char	num[10];
	int		i;

	i = 0;
	while (i < 10)
	{
		num[i] = 0;
		i++;
	}
	rec(num, 0, 0, n);
}
