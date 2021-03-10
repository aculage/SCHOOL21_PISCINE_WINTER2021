/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:12:09 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/27 19:12:10 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

int		ft_strlenl(char *str)
{
	int cnt;

	cnt = 0;
	while (*str != 0)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

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

void	ft_putstrmod(char *str)
{
	write(1, str, ft_strlenl(str));
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int cnt;

	cnt = 0;
	while ((par + cnt)->str != NULL)
	{
		ft_putstrmod((par + cnt)->str);
		ft_putnbr((par + cnt)->size);
		write(1, "\n", 1);
		ft_putstrmod((par + cnt)->copy);
		cnt++;
	}
}
