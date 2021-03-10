/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:44:14 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/20 20:45:07 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char strend_found;
	char *ret;

	ret = dest;
	strend_found = 0;
	while (n > 0)
	{
		if (strend_found == 0 && *src != 0)
		{
			*dest = *src;
		}
		else
		{
			strend_found = 1;
			*dest = 0;
		}
		n--;
		dest++;
		src++;
	}
	return (ret);
}
