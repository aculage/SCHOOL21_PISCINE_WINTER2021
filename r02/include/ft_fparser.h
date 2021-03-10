#ifndef FT_PARSER_H
# define FT_PARSER_H
# include "ft.h"
# include "ft_list.h"
# include "ft_dict.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void	parsedict(int file, t_list *dict);

#endif

