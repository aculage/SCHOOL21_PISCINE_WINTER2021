/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:21:04 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/20 20:27:45 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (*(str + cnt) != 0)
	{
		cnt++;
	}
	return (cnt);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int ret;
	unsigned int n;

	n = 0;
	ret = ft_strlen(src);
	while (n < size - 2 || *(src + n) != 0)
	{
		*(dest + n) = *(src + n);
		n++;
	}
	*(dest + n + 1) = 0;
	return (ret);
}
