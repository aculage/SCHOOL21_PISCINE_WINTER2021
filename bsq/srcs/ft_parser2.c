#include "ft.h"
#include "ft_parser.h"
#include <stdio.h>//TODO: REMOVE

extern int	g_errnum;

void			ft_setsymb(char *symb, char *str)
{
	*(symb + 0) = *(str + ft_strlen(str) - 4);
	*(symb + 1) = *(str + ft_strlen(str) - 3);
	*(symb + 2) = *(str + ft_strlen(str) - 2);
}

void			readrest(t_squaremap *sqmap, int file, char *buf, int pos)
{
	int cnt;
	int netread;

	cnt = 2;
	netread = read(file, buf, pos + 1);
	while (netread == pos + 1)
	{
		createrow(sqmap, cnt, buf, pos);
		if (sqmap == NULL)
		{
			printf("HERE\n");
			return ;
		}
		if (cnt > sqmap->row_num)
		{
			sqmap->row_num = cnt + 1;
			if (ft_error_checker(&sqmap, MAPERROR, 2))
				return ;
		}
		cnt++;
		netread = read(file, buf, pos + 1);
	}
	if (cnt > sqmap->row_num)
	{
		
		sqmap->row_num = cnt;
		ft_error_checker(&sqmap, MAPERROR, 2);
		return ;
	}
	if (cnt < sqmap->row_num)
	{
		sqmap->row_num = cnt + 1;
		ft_error_checker(&sqmap, MAPERROR, 2);
	}
}

void			setinitvals(t_squaremap *ret, char *str)
{
	ft_setsymb(ret->symb, str);
	*(str + ft_strlen(str) - 4) = 0;
	ret->row_num = ft_atoi(str);
	if (ret->row_num != -1 && !(ft_validate(ret)))
		ret->map = (int**)malloc(sizeof(int*) * ret->row_num);
	else
		ret->map = NULL;
}

void			getfirststr(int file, char *buf, char **str)
{
	int curr_read;

	curr_read = 2;
	while (*buf != '\n' && curr_read != 0)
	{
		curr_read = read(file, buf, 1);
		*(buf + 1) = 0;
		*str = ft_strappend(*str, buf, ft_strlen(buf));
	}
}

int				getfirstmaprow(int *pos, int file, int *size, char **buf)
{
	int netread;
	int curr_read;

	netread = 2;
	curr_read = 2;
	while (*pos == -1 && curr_read != 0)
	{
		*buf = ft_realloc(*buf, *size, *size * 2, 0);
		curr_read = read(file, *buf + *size, *size);
		*pos = locnewln(*buf, *size * 2);
		*size *= 2;
		netread += curr_read;
	}
	return (netread);
}
