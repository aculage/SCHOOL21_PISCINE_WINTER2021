/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:36:37 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/21 18:38:47 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*ret;
	unsigned int	count;

	count = 0;
	ret = dest;
	while (*dest != 0)
	{
		dest++;
	}
	while (*src != 0 && count < nb)
	{
		*dest = *src;
		dest++;
		src++;
		count++;
	}
	dest++;
	*dest = 0;
	return (ret);
}
