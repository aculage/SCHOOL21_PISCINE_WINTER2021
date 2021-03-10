/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:25:38 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/02 19:26:21 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

int	ispc(char a)
{
	if (a == '\t' || a == '\v' || a == '\f')
	{
		return (1);
	}
	if (a == ' ' || a == '\n' || a == '\r')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int ret;
	int flipsign;

	ret = 0;
	flipsign = 1;
	while (ispc(*str) > 0 && *str != 0)
		str++;
	while ((*str == '+' || *str == '-') && (*str != 0))
	{
		if (*str == '-')
			flipsign *= -1;
		str++;
	}
	while ((*str >= 48 && *str <= 57) && (*str != 0))
	{
		ret *= 10;
		ret += (*str - 48);
		str++;
	}
	ret *= flipsign;
	return (ret);
}
