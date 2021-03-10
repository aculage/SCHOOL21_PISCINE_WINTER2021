/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:41:40 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/25 12:41:48 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int n;

	n = 0;
	while (++n < argc)
		ft_putstr(*(argv + n));
}
