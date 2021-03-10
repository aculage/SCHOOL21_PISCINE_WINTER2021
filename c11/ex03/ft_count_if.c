/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:22:01 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/02 19:22:02 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int cnt;
	int ret;

	ret = 0;
	cnt = 0;
	while (cnt < length)
		if (f(*(tab + cnt++)))
			ret++;
	return (ret);
}
