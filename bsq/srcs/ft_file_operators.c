#include "ft_print.h"

extern int	g_errnum;

void		ft_close_file(int file_desc)
{
	if (!(file_desc == STDOUT_FILENO) && !(file_desc == STDIN_FILENO))
		if (close(file_desc) == -1)
			g_errnum = FILEERROR;
}

void		ft_safe_write(int file_desc, char *str, int size)
{
	if (write(file_desc, str, size) == -1)
		g_errnum = WRITEERROR;
}

int		ft_open_file(char *str)
{
	int file_desc;

	file_desc = -1;
	if (*str == '\0')
		file_desc = STDIN_FILENO;
	else
		file_desc = open(str, O_RDONLY);
	if (file_desc == -1)
		g_errnum = FILEERROR;
	return (file_desc);
}
