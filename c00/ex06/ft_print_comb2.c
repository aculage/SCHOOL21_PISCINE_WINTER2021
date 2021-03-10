/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:27:22 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/17 17:27:29 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert(short *buf, char *res)
{
	res[0] = buf[0] / 10 % 10 + 48;
	res[1] = buf[0] % 10 + 48;
	res[2] = 32;
	res[3] = buf[1] / 10 % 10 + 48;
	res[4] = buf[1] % 10 + 48;
}

void	ft_print_comb2(void)
{
	short	buf[2];
	char	res[5];
	char	put[2];

	res[2] = ' ';
	put[0] = ',';
	put[1] = ' ';
	buf[0] = 0;
	while (buf[0] <= 98)
	{
		buf[1] = buf[0] + 1;
		while (buf[1] <= 99)
		{
			convert(buf, res);
			write(1, res, 5);
			if (buf[1] != 99 || buf[0] != 98)
			{
				write(1, put, 2);
			}
			buf[1]++;
		}
		buf[0]++;
	}
}
