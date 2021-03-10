/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:48:36 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/01 21:07:57 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <string.h>

void	print(int stream, char *buffer, int size)
{
	write(stream, buffer, size);
}

int		read_f(int stream, char *buffer, int size)
{
	int rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(stream, buffer, size);
		if (rd != -1)
			print(1, buffer, rd);
		else
		{
			return (-1);
		}
	}
	if (rd == -1)
		return (rd);
	return (0);
}

void	errhandle(char **argv, int strnum)
{
	write(2, *(argv), ft_strlen(*argv + 1));
	write(2, ": ", 2);
	if (strnum != 0)
		write(2, *(argv + strnum), ft_strlen(*argv + strnum));
	else
		write(2, "stdin", 6);
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	return ;
}

int		ft_strcmp(char *s1, char *s2)
{
	int n;

	n = 0;
	while (*(s1 + n) == *(s2 + n))
	{
		if (*(s1 + n) == 0)
		{
			return (0);
		}
		n++;
	}
	return ((unsigned char)*(s1 + n) - (unsigned char)*(s2 + n));
}

int		ft_display_file(char *path, int file, char **argv, int strnum)
{
	char	buf[BUFSIZE];

	if (file == 0)
	{
		file = open(path, O_RDONLY);
		if (file == -1)
		{
			errhandle(argv, strnum);
			return (0);
		}
		if (-1 == read_f(file, buf, BUFSIZE))
		{
			errhandle(argv, strnum);
		}
		close(file);
	}
	else
	{
		if (-1 == read_f(file, buf, BUFSIZE))
		{
			errhandle(argv, strnum);
		}
	}
	return (0);
}
