#include "ft_bsq.h"
#include "ft_print.h"
#include "ft_error.h"

int		ft_min_3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	ft_check_borders(t_squaremap *my_map)
{
	int	curr;

	my_map->top_x = -1;
	curr = my_map->row_num - 1;
	while (curr >= 0)
	{
		if (my_map->map[curr][0] == 1)
		{
			my_map->top_x = 0;
			my_map->top_y = curr;
			my_map->max_size = 1;
		}
		--curr;
	}
	curr = my_map->col_num - 1;
	while (curr >= 0)
	{
		if (my_map->map[0][curr] == 1)
		{
			my_map->top_x = curr;
			my_map->top_y = 0;
			my_map->max_size = 1;
		}
		--curr;
	}
}

void	ft_find_biggest_square(t_squaremap *my_map)
{
	int		x;
	int		y;

	if (my_map == NULL)
		return ;
	y = 1;
	my_map->top_x = -1;
	my_map->top_y = -1;
	my_map->max_size = 0;
	ft_check_borders(my_map);
	while (y < my_map->row_num)
	{
		x = 1;
		while (x < my_map->col_num)
		{
			ft_fill_cell(my_map, y, x);
			++x;
		}
		++y;
	}
}

void	ft_fill_cell(t_squaremap *my_map, int y, int x)
{
	if (my_map->map[y][x] != 0)
	{
		my_map->map[y][x] = ft_min_3(my_map->map[y - 1][x - 1],
		my_map->map[y][x - 1], my_map->map[y - 1][x]) + 1;
		if (my_map->max_size < my_map->map[y][x])
		{
			my_map->max_size = my_map->map[y][x];
			my_map->top_y = y - my_map->max_size + 1;
			my_map->top_x = x - my_map->max_size + 1;
		}
	}
}

void	ft_map_dump(t_squaremap **my_map)
{
	while ((*my_map)->row_num > 0)
	{
		--((*my_map)->row_num);
		free((*my_map)->map[(*my_map)->row_num]);
	}
	free((*my_map)->map);
	free((*my_map));
	*my_map = NULL;
}
