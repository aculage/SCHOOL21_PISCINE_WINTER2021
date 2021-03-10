/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:43:22 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/17 18:43:40 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
