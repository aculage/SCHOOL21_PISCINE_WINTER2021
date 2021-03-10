/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:00:24 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/01 21:01:05 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"
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

int		main(int argc, char **argv)
{
	int cnt;

	cnt = 0;
	if (argc == 1)
		ft_display_file("", 1, argv, cnt);
	cnt = 1;
	while (cnt < argc)
	{
		if (!(ft_strcmp(*(argv + cnt), "-")))
			ft_display_file("", 1, argv, cnt);
		else
			ft_display_file(*(argv + cnt), 0, argv, cnt);
		cnt++;
	}
}
