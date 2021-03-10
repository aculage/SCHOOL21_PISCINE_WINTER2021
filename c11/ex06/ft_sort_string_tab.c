/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:44:30 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/02 19:11:17 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_putstr(char *str)
{
	int		cnt;
	char	*out;

	cnt = 0;
	out = str;
	while (*str != 0)
	{
		str++;
		cnt++;
	}
	write(1, out, cnt);
}

char	**sort(char **arr)
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
			if (ft_strcmp(arr[i], arr[ii]) > 0)
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

void	ft_sort_string_tab(char **argv)
{
	argv = sort(argv);
	return ;
}
