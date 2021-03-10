/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:55:41 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/26 19:55:46 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/errno.h>

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

char	*ft_strdup(char *src)
{
	char	*ret;
	int		n;

	n = 0;
	ret = malloc(ft_strlen(src) + 1);
	if (ret != (void*)0)
	{
		while (*(src + n++) != 0)
			*(ret + n - 1) = *(src + n - 1);
		*(ret + n - 1) = 0;
		return (ret);
	}
	else
	{
		errno = ENOMEM;
		return (NULL);
	}
}
