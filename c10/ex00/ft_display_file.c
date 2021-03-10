/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:48:36 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/01 17:49:36 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <fcntl.h>

void	print(int stream, char *buffer, int size)
{
	write(stream, buffer, size);
}

void	read_f(int stream, char *buffer, int size)
{
	int rd;

	rd = read(stream, buffer, size);
	while (rd > 0)
	{
		print(1, buffer, rd);
		rd = read(stream, buffer, size);
	}
	if (rd == -1)
		errhandle(CNNTRDFILE);
}

void	errhandle(int errid)
{
	if (errid == FMISSING)
	{
		write(1, "File name missing.\n", 20);
		return ;
	}
	if (errid == TMNYARGS)
	{
		write(1, "Too many arguments.\n", 21);
		return ;
	}
	if (errid == CNNTRDFILE)
	{
		write(1, "Cannot read file.\n", 19);
		return ;
	}
}

int		main(int argc, char **argv)
{
	char	buf[BUFSIZE];
	int		file;

	if (argc == 1)
	{
		errhandle(FMISSING);
		return (0);
	}
	if (argc > 2)
	{
		errhandle(TMNYARGS);
		return (0);
	}
	file = open(*(argv + 1), O_RDONLY);
	if (file == -1)
	{
		errhandle(CNNTRDFILE);
		return (0);
	}
	read_f(file, buf, BUFSIZE);
}
