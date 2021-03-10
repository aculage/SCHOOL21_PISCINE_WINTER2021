#include "ft_parser.h"
#include "ft_error.h"
#include "ft.h"
#include "ft_print.h"
#include <stdio.h>//TODO: REMOVE

extern int	g_errnum;

int				ft_validate(t_squaremap *map)
{
	if (g_errnum != MAPERROR && g_errnum != MAPERRHNDLD)
	{
		if (map->symb[0] == map->symb[1])
			g_errnum = MAPERROR;
		if (map->symb[1] == map->symb[2])
			g_errnum = MAPERROR;
		if (map->symb[0] == map->symb[2])
			g_errnum = MAPERROR;
		if (map->row_num == -1)
			g_errnum = MAPERROR;
	}
	return (ft_error_checker(&map, 0, 0));
}

void			initgen(int file, t_squaremap *ret)
{
	char		*str;
	char		*buf;

	str = malloc(1);
	*str = 0;
	buf = malloc(2);
	*buf = 0;
	if (str == NULL || buf == NULL)
		if (ft_error_checker(&ret, MEMALLOCERR, 0) == 1)
			return ;
	getfirststr(file, buf, &str);
	setinitvals(ret, str);
	free(buf);
	free(str);
	if (ret->row_num < 0)
		if (ft_error_checker(&ret, MAPERROR, 0) == 1)
			return ;
	if (ret->map == NULL)
		if (ft_error_checker(&ret, MEMALLOCERR, 0) == 1)
			return ;
}

void			createrow(t_squaremap *sqmap, int rownum, char *buffer,
int size)
{
	int cnt;

	cnt = 0;
	sqmap->map[rownum] = (int *)malloc(size * sizeof(int));
	if (sqmap->map[rownum] == NULL)
		ft_error_checker(&sqmap, MEMALLOCERR, 0);
	while (cnt < size)
	{
		if (buffer[cnt] == sqmap->symb[0])
			sqmap->map[rownum][cnt] = 1;
		else if (buffer[cnt] == sqmap->symb[1])
			sqmap->map[rownum][cnt] = 0;
		else
		{
			sqmap->row_num = rownum;
			ft_error_checker(&sqmap, MAPERROR, 2);
			break ;
		}
		cnt++;
	}
}

int				readfs(t_squaremap *sqmap, int file)
{
	char	*buf;
	int		size;
	int		pos;
	int		netread;

	size = 2;
	buf = malloc(size);
	if (buf == NULL)
		ft_error_checker(&sqmap, MEMALLOCERR, 0);
	read(file, buf, size);
	pos = locnewln(buf, size);
	netread = getfirstmaprow(&pos, file, &size, &buf);
	createrow(sqmap, 0, buf, pos);
	buf = ft_realloc(buf + pos + 1, size - pos - 1, pos + 1, pos + 1);
	netread += read(file, buf + (size - pos) - 1, pos - (size - pos) + 2);
	if (sqmap->row_num == 1)
		return (getresforone(netread, sqmap, pos));
	createrow(sqmap, 1, buf, pos);
	readrest(sqmap, file, buf, pos);
	free(buf);
	return (pos);
}

t_squaremap		*parsefile(char *path)
{
	t_squaremap	*ret;
	int			file;

	ret = (t_squaremap*)malloc(sizeof(t_squaremap));
	if (ret == NULL)
	{
		ft_error_checker(&ret, MEMALLOCERR, 0);
		return (NULL);
	}
	file = ft_open_file(path);
	if (ft_error_checker(&ret, 0, 0) == 1)
	{
		free(ret);
		return (NULL);
	}
	initgen(file, ret);
	if (ft_error_checker(&ret, 0, 0) == 1)
	{
		free(ret);
		return (NULL);
	}
	ret->col_num = readfs(ret, file);
	if (ft_error_checker(&ret, 0, 0) == 1)
		return (NULL);
	return (ret);
}
