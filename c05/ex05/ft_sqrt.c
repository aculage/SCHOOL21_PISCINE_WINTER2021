/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:35:34 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/24 19:38:08 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recf(int lvalue, int rvalue, int nb)
{
	int	mid;

	mid = (lvalue + rvalue) / 2;
	if (rvalue - lvalue == 1)
		return (0);
	if (nb / mid < mid)
		return (recf(lvalue, mid, nb));
	if (nb / mid > mid)
		return (recf(mid, rvalue, nb));
	if (nb % mid != 0)
		return (0);
	return (mid);
}

int	ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	return (recf(0, nb, nb));
}
