#include "ft_bsq.h"
#include "ft_print.h"
#include "ft_error.h"
#include "ft.h"

int		g_errnum;

int		main(int argc, char **argv)
{
	t_squaremap	*my_map;
	int			count;

	g_errnum = 0;
	if (argc == 1)
	{
		my_map = (parsefile(""));
		ft_find_biggest_square(my_map);
		ft_print_map(my_map);
		if (g_errnum == 0)
			ft_map_dump(&my_map);
	}
	count = 1;
	while (count < argc)
	{
		g_errnum = 0;
		my_map = (parsefile(argv[count]));
		ft_find_biggest_square(my_map);
		ft_print_map(my_map);
		if (g_errnum == 0)
			ft_map_dump(&my_map);
		if ((argc > 2) && (count != argc - 1))
		{
			if (g_errnum != 0)
				write(2, "\n", 1);
			else
				write(1, "\n", 1);
		}
		++count;
	}
	return (0);
}
