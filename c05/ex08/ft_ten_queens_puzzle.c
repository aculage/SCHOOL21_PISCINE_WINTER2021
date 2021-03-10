/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:53:30 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/24 19:53:32 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printrow(char *row)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = *(row + i) + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	nullify(char *arr, int size)
{
	while (size-- >= 0)
	{
		arr[size] = 0;
	}
}

void	filler(char *depth_row, char *current_stand, int depth)
{
	int i;

	i = 0;
	while (i < depth)
	{
		depth_row[(int)current_stand[i]] = 1;
		if (current_stand[i] - (depth - i) >= 0)
			depth_row[(int)current_stand[i] - (depth - i)] = 1;
		if (current_stand[i] + (depth - i) <= 9)
			depth_row[(int)current_stand[i] + (depth - i)] = 1;
		i++;
	}
}

void	next_row(char *current_stand, int depth, int *count)
{
	int		i;
	char	depth_row[10];

	i = 0;
	nullify(depth_row, 10);
	if (depth == 10)
	{
		*count = *count + 1;
		printrow(current_stand);
		return ;
	}
	filler(depth_row, current_stand, depth);
	while (i < 10)
	{
		if (depth_row[i] == 0)
		{
			current_stand[depth] = i;
			next_row(current_stand, depth + 1, count);
		}
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	char	start[10];
	int		cnt;

	cnt = 0;
	while (cnt++ < 10)
		start[cnt - 1] = 0;
	cnt = 0;
	next_row(start, 0, &cnt);
	return (cnt);
}
