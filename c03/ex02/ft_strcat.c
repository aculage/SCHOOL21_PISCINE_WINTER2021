/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:35:20 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/21 18:36:27 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char *ret;

	ret = dest;
	while (*dest != 0)
	{
		dest++;
	}
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
	return (ret);
}
