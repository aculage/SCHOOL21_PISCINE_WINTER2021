/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:33:34 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/21 18:34:59 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int cnt;

	cnt = 0;
	while (*s1 == *s2 && cnt < n)
	{
		if (*s1 == 0)
		{
			return (0);
		}
		s1++;
		s2++;
		cnt++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
