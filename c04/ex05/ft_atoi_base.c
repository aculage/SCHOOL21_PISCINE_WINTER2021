/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:06:12 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/23 14:17:42 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ispc(char a)
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

	l = 0;
	while (l < 256)
	{
		chck[l] = 0;
		l++;
	}
	if (ft_strlen(str) < 2)
		return (1);
	while (*str != 0)
	{
		chck[*(unsigned char *)str]++;
		if (chck[*(unsigned char *)str] > 0)
		{
			if (chck[*(unsigned char *)str] > 1 && ispc(*str))
				return (1);
			if (chck[*(unsigned char *)str] > 2 || *str == '-' || *str == '+')
				return (1);
		}
		str++;
	}
	return (0);
}

int		getval(char in, char *base)
{
	int i;
	int pw;
	int ret;

	pw = 0;
	i = 0;
	while (base[i] != in && base[i] != 0)
	{
		i++;
	}
	if (base[i] == 0)
		return (-1);
	ret = i;
	return (ret);
}

int		ft_atoi_base(char *str, char *base)
{
	int ret;
	int flipsign;

	ret = 0;
	flipsign = 1;
	while (ispc(*str) > 0 && *str != 0)
		str++;
	if (validator(base))
		return (0);
	while ((*str == '+' || *str == '-') && (*str != 0))
	{
		if (*(str) == '-')
			flipsign *= -1;
		str++;
	}
	while (*str != 0)
	{
		if (getval(*str, base) == -1)
			return (ret *= flipsign);
		ret *= ft_strlen(base);
		ret += getval(*str, base);
		str++;
	}
	ret *= flipsign;
	return (ret);
}
