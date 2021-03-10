#ifndef FT_ERROR_H
# define FT_ERROR_H
# include "ft_bsq.h"
# define MEMALLOCERR	1
# define MAPERROR		2
# define FILEERROR		3
# define WRITEERROR		30
# define ARGSINVALID	4
# define MAPERRHNDLD	228

/*
**Closes programm and displays error message. Every time you call
**it don't forget to use ft_map_dump() before!
*/
void	ft_error_handler(int errnum);
/*
**Checks if global variable g_errnum is set to non-zero
*/
char	ft_error_checker(t_squaremap **my_map, int errnum, int call_dump);

#endif
