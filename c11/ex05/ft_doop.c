/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:20:31 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/02 19:27:07 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"
#include <stdio.h>

int g_err;

void	ft_putnbr(int nb)
{
	int		devaluator;
	char	minus;
	char	num;
	char	flag;

	devaluator = 1000000000;
	flag = 0;
	minus = '-';
	if (nb < 0)
	{
		write(1, &minus, 1);
	}
	nb = nb > 0 ? -nb : nb;
	while (devaluator > 0)
	{
		num = -(nb / devaluator % 10);
		if ((num > 0 || flag > 0) || (devaluator == 1))
		{
			flag = 1;
			num += 48;
			write(1, &num, 1);
			nb %= devaluator;
		}
		devaluator /= 10;
	}
}

void	setfunc(int (*f[5])(int, int))
{
	(*f) = sum;
	(*(f + 1)) = div;
	(*(f + 2)) = sub;
	(*(f + 3)) = mul;
	(*(f + 4)) = mod;
}

int		getop(char *op)
{
	if (*(op) == '+' && *(op + 1) == 0)
		return (0);
	if (*(op) == '/' && *(op + 1) == 0)
		return (1);
	if (*(op) == '-' && *(op + 1) == 0)
		return (2);
	if (*(op) == '*' && *(op + 1) == 0)
		return (3);
	if (*(op) == '%' && *(op + 1) == 0)
		return (4);
	return (-1);
}

int		main(int argc, char **argv)
{
	int (*f[5])(int, int);
	int arg1;
	int arg2;
	int (*func)(int, int);
	int res;

	if (argc > 4 || argc < 4)
		return (0);
	setfunc(f);
	if (getop(*(argv + 2)) == -1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	arg1 = ft_atoi(*(argv + 1));
	arg2 = ft_atoi(*(argv + 3));
	func = (*(f + getop(*(argv + 2))));
	res = func(arg1, arg2);
	if (g_err != -1)
		ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}
