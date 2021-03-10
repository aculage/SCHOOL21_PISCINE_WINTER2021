/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:56:23 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/26 19:59:48 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int				*ret;
	long long int	n;

	n = 0;
	if (min >= max)
		return (NULL);
	ret = malloc(4 * ((long long int)max - (long long int)min));
	while (n < ((long long int)max - (long long int)min))
	{
		*(ret + n) = min + (int)n;
		n++;
	}
	return (ret);
}
