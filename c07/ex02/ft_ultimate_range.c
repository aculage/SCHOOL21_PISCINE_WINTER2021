/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:07:35 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/26 20:09:08 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	long long int	n;

	n = 0;
	if (range == NULL)
		return (-1);
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(4 * ((long long int)max - (long long int)min));
	while (n < ((long long int)max - (long long int)min))
	{
		*(*range + n) = min + n;
		n++;
	}
	if (n > 2147483647)
		return (-1);
	return (max - min);
}
