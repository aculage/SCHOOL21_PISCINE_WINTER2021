/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:38:59 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/25 12:49:00 by hbrendon         ###   ########.fr       */
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
	(void)argc;
	ft_putstr(*argv);
}
