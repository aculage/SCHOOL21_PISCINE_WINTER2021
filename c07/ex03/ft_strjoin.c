/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:16:30 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/26 20:16:33 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strcat(char *dest, char *src)
{
	int n;

	n = 0;
	while (*(dest + n) != 0)
		n++;
	while (*src != 0)
	{
		*(dest + n) = *src;
		src++;
		n++;
	}
	*(dest + n) = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		n;
	char	*ret;
	int		sz;

	sz = 1;
	n = 0;
	if (size <= 0)
	{
		ret = malloc(1);
		ret[0] = '\0';
		return (ret);
	}
	while (n++ < size)
		sz += ft_strlen(*(strs + n - 1));
	sz += ft_strlen(sep) * (size - 1);
	ret = malloc(sz);
	ret[0] = '\0';
	n = 0;
	while (n++ < size)
	{
		ret = ft_strcat(ret, *(strs + n - 1));
		if ((n - 1) != size - 1)
			ret = ft_strcat(ret, sep);
	}
	return (ret);
}
