/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:44:30 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/03 17:30:07 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	**sort(char **arr, int (*cmp)(char *, char*))
{
	int		i;
	int		ii;
	char	*tmp;

	i = 0;
	ii = 1;
	while (*(arr + i) != NULL)
	{
		ii = i;
		while (*(arr + ii) != NULL)
		{
			if (cmp(arr[i], arr[ii]) > 0)
			{
				tmp = arr[ii];
				arr[ii] = arr[i];
				arr[i] = tmp;
			}
			ii++;
		}
		i++;
	}
	return (arr);
}

void	ft_advanced_sort_string_tab(char **argv, int (*cmp)(char *, char*))
{
	argv = sort(argv, cmp);
	return ;
}
