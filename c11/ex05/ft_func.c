/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:20:24 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/02 19:26:15 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

extern int g_err;

int	sum(int a, int b)
{
	g_err = 0;
	return (a + b);
}

int	div(int a, int b)
{
	if (b != 0)
		return (a / b);
	write(1, "Stop : division by zero", 23);
	g_err = -1;
	return (0);
}

int	sub(int a, int b)
{
	g_err = 0;
	return (a - b);
}

int	mul(int a, int b)
{
	g_err = 0;
	return (a * b);
}

int	mod(int a, int b)
{
	if (b != 0)
	{
		return (a % b);
	}
	write(1, "Stop : modulo by zero", 21);
	g_err = -1;
	return (0);
}
