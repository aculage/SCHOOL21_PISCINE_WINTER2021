/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:42:43 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/21 19:49:34 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str != 0)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

void			stud(char **src, char **dest, unsigned int *count)
{
	**dest = **src;
	*src = *src + 1;
	*dest = *dest + 1;
	*count = *count + 1;
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	sz;
	int				slen;

	count = 0;
	sz = 0;
	slen = ft_strlen(src);
	while (*dest != 0)
	{
		dest++;
		sz++;
	}
	if (sz >= size)
	{
		return (size + slen);
	}
	while (*src != 0 && count < size - sz - 1)
	{
		stud(&src, &dest, &count);
	}
	dest++;
	*dest = 0;
	return (sz + slen);
}
