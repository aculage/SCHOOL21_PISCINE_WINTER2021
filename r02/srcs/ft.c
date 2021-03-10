/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:43:22 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/07 13:53:34 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int	ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (*(str + cnt) != 0)
	{
		cnt++;
	}
	return (cnt);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_putstr(int stream, char *str)
{
	write(stream, str, ft_strlen(str));
}
