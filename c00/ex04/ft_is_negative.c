/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:59:07 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/17 12:59:14 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char nn;
	char p;

	nn = 'N';
	p = 'P';
	if (n >= 0)
	{
		write(1, &p, 1);
	}
	else
	{
		write(1, &nn, 1);
	}
}
