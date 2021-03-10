/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:02:33 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/23 21:28:15 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
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

int		validator(char *str)
{
	int		l;
	int		chck[256];
	int		n;

	l = 0;
	n = 0;
	while (l++ < 256)
		chck[l - 1] = 0;
	l = 0;
	while (*(str + n) != 0)
	{
		chck[(unsigned char)*(str + n)]++;
		n++;
	}
	if (ft_strlen(str) < 2)
		return (1);
	while (l < 256)
	{
		if (chck[l] > 1 || chck['-'] > 0 || chck['+'] > 0)
			return (1);
		l++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		bs;
	char	buf[35];
	int		ll;

	ll = 0;
	if (validator(base))
		return ;
	bs = ft_strlen(base);
	if (nbr >= 0)
		nbr = -nbr;
	else
		write(1, "-", 1);
	if (nbr == 0)
		write(1, base, 1);
	while (nbr < 0)
	{
		buf[ll] = base[-(nbr % bs)];
		nbr /= bs;
		ll++;
	}
	while (ll > 0)
	{
		ll--;
		write(1, &buf[ll], 1);
	}
}
