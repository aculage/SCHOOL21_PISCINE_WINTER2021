/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:40:47 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/26 21:41:02 by hbrendon         ###   ########.fr       */
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

int		validator(char *str)
{
	int		l;
	int		chck[256];

	l = 0;
	while (l++ < 256)
	{
		chck[l - 1] = 0;
	}
	if (ft_strlen(str) < 2)
		return (1);
	l = 0;
	while (*(str + l) != 0)
	{
		chck[(unsigned char)*(str + l)]++;
		if (chck[(unsigned char)*(str + l)] > 0)
		{
			if (chck[(unsigned char)*(str + l)] >= 1 && ispc(*(str + l)))
				return (1);
			if (chck[(unsigned char)*(str + l)] >= 2 ||
					*(str + l) == '-' || *(str + l) == '+')
				return (1);
		}
		l++;
	}
	return (0);
}

char	*rev_arr(char *str, int size)
{
	int n;
	int swap;
	int lsh;

	if (*str == '-')
		lsh = 1;
	else
		lsh = 0;
	n = 0;
	while (n < size / 2)
	{
		swap = *(str + size - n - 1);
		*(str + size - n - 1) = *(str + n + lsh);
		*(str + n + lsh) = swap;
		n++;
	}
	return (str);
}
