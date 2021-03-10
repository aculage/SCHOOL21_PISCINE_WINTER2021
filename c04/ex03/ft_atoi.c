/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:56:55 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/23 14:12:54 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
