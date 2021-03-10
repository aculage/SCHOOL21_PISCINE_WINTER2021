#include "ft.h"
#include "ft_parser.h"

int		getresforone(int netread, t_squaremap *sqmap, int pos)
{
	if (netread != pos + 1)
	{
		ft_error_checker(&sqmap, MAPERROR, 0);
		return (-1);
	}
	else
		return (pos);
}