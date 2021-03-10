#include "ft_print.h"

extern int	g_errnum;

void		ft_print_map(t_squaremap *my_map)
{
	int		y;
	int		file_desc;
	char	*out_str;

	file_desc = STDOUT_FILENO;
	if (my_map == NULL)
	{
		return ;
	}
	out_str = (char*)malloc(sizeof(char) * my_map->col_num + 1);
	if (out_str == NULL)
		g_errnum = MEMALLOCERR;
	if (ft_error_checker(&my_map, 0, 1) == 1)
		return ;
	y = 0;
	while (y < my_map->row_num)
	{
		ft_prepare_print_str(my_map, y, out_str);
		ft_safe_write(file_desc, out_str, my_map->col_num + 1);
		if (ft_error_checker(&my_map, 0, 1) == 1)
			return ;
		++y;
	}
	ft_close_file(file_desc);
	if (ft_error_checker(&my_map, 0, 1) == 1)
		return ;
	free(out_str);
}

void		ft_prepare_print_str(t_squaremap *my_map, int y, char *out_str)
{
	int		x;

	x = 0;
	while (x < my_map->col_num)
	{
		if (my_map->map[y][x] == 0)
			*(out_str + x) = my_map->symb[1];
		else if ((my_map->top_x <= x) && (my_map->top_y <= y)
		&& (x <= my_map->top_x + my_map->max_size - 1)
		&& (y <= my_map->top_y + my_map->max_size - 1))
			*(out_str + x) = my_map->symb[2];
		else
			*(out_str + x) = my_map->symb[0];
		++x;
	}
	*(out_str + x) = '\n';
}

void		ft_putstr(char *str, int file_desc)
{
	int count;

	count = 0;
	while (*(str + count) != '\0')
		++count;
	ft_safe_write(file_desc, str, count);
}
