/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:27:19 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/26 21:27:21 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ispc(char a);
int		ft_strlen(char *str);
int		validator(char *str);
int		getval(char in, char *base);
char	*rev_arr(char *str, int size);

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

char	*mem_realloc(char *str1, int add_len)
{
	char	*str;
	int		n;

	n = 0;
	str = malloc(add_len + 1);
	while (*(str1 + n) != 0)
	{
		*(str + n) = *(str1 + n);
		n++;
	}
	free(str1);
	*(str + n) = 0;
	return (str);
}

char	*ininumgen(int *nbr, int *ll, char *base)
{
	char *ret;

	ret = malloc(2);
	if (*nbr >= 0)
	{
		*nbr = -*nbr;
		ret[0] = 0;
		ret[0] = 0;
		*ll = 1;
	}
	else
	{
		ret[0] = '-';
		ret[1] = 0;
		*ll = 2;
	}
	if (*nbr == 0)
	{
		ret[0] = *base;
		ret[1] = 0;
		*ll = 2;
	}
	return (ret);
}

char	*ft_setnbr_base(int nbr, char *base)
{
	int		bs;
	char	*ret;
	int		ll;

	ll = 0;
	ret = malloc(2);
	ret[0] = '\0';
	if (validator(base))
		return (NULL);
	bs = ft_strlen(base);
	ret = ininumgen(&nbr, &ll, base);
	while (nbr < 0)
	{
		ret = mem_realloc(ret, ll + 1);
		ret[ll - 1] = base[-(nbr % bs)];
		nbr /= bs;
		ll++;
	}
	ret = rev_arr(ret, ll - 1);
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*ret;
	int		transfer;

	if ((validator(base_from) || (validator(base_to))))
		return (NULL);
	transfer = ft_atoi_base(nbr, base_from);
	ret = ft_setnbr_base(transfer, base_to);
	return (ret);
}
