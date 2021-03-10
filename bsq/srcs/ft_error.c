#include "ft_bsq.h"
#include "ft_error.h"
#include "ft_print.h"

extern int	g_errnum;

void	ft_error_handler(int errnum)
{
	if (errnum == MAPERROR)
	{
		ft_putstr("map error\n", 2);
		g_errnum = MAPERRHNDLD;
	}
}

char	ft_error_checker(t_squaremap **my_map, int errnum, int call_dump)
{
	if (errnum != 0)
	{
		if (errnum == MAPERROR)
			g_errnum = g_errnum == MAPERRHNDLD ? MAPERRHNDLD : MAPERROR;
		else
			g_errnum = errnum;
	}
	if (g_errnum != 0)
	{
		if (call_dump == 1)
			ft_map_dump(my_map);
		else if (call_dump == 2)
			ft_map_dump(my_map);
		ft_error_handler(g_errnum);
		return (1);
	}
	return (0);
}
