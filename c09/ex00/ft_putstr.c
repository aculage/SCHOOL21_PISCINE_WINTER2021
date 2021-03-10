/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:14:09 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/01 19:06:33 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (*(str + cnt) != 0)
	{
		cnt++;
	}
	return (cnt);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
