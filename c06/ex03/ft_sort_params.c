/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:44:30 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/25 12:46:47 by hbrendon         ###   ########.fr       */
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

char	**sort(char **arr, int size)
{
	int		i;
	int		ii;
	char	*tmp;

	i = 1;
	ii = 2;
	while (i < size)
	{
		ii = i;
		while (ii < size)
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

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	argv = sort(argv, argc);
	while (i++ < argc)
	{
		ft_putstr(argv[i - 1]);
		write(1, "\n", 1);
	}
}
