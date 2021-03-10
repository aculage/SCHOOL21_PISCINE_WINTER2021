#ifndef FT_BSQ_H
# define FT_BSQ_H
# include <stdlib.h>

typedef	struct		s_squaremap
{
	int		**map;
	char	symb[3];
	int		row_num;
	int		col_num;
	int		max_size;
	int		top_x;
	int		top_y;
}					t_squaremap;

/*
**Finds the biggest square on the map
*/
void				ft_find_biggest_square(t_squaremap *my_map);
/*
**Frees all alocated for map memory. Needs to be manually called
**BEFORE calling ft_error_handler()
*/
void				ft_map_dump(t_squaremap **my_map);
/*
**Checks if first row and line has any non-obstacle characters
*/
void				ft_check_borders(t_squaremap *my_map);
/*
**Finds minimum value between 3 values given as parameters
*/
int					ft_min_3(int a, int b, int c);
/*
**Runs calculations for the current element of the matrix
*/
void				ft_fill_cell(t_squaremap *my_map, int y, int x);

#endif
