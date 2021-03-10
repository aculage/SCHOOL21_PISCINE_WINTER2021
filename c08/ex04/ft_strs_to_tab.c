/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:10:37 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/27 19:10:48 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
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

char				*ft_strcpy(char *dest, char *src)
{
	char *ret;

	ret = dest;
	while (*src != 0)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = *src;
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*ret;
	int					cnt;

	cnt = 0;
	ret = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (ret == NULL)
		return (ret);
	while (cnt < ac)
	{
		(ret + cnt)->str = *(av + cnt);
		(ret + cnt)->copy = malloc(sizeof(char) * (ft_strlen(*(av + cnt)) + 1));
		if ((ret + cnt)->copy == NULL)
			return (NULL);
		ft_strcpy((ret + cnt)->copy, *(av + cnt));
		(ret + cnt)->size = ft_strlen(*(av + cnt));
		cnt++;
	}
	(ret + cnt)->str = NULL;
	return (ret);
}
