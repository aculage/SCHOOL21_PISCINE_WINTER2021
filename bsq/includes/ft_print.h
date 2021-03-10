#ifndef FT_PRINT_H
# define FT_PRINT_H
# include "ft_bsq.h"
# include "ft_parser.h"
# include "ft_error.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

/*
**Prints map to STDOUT
*/
void	ft_print_map(t_squaremap *my_map);
/*
**Writes to a file, handles errors if the file was closed mid-write
*/
void	ft_safe_write(int file_desc, char *str, int size);
/*
**Writes a line excluding terminator symbol to a file
*/
void	ft_putstr(char *str, int file_desc);
/*
**Closes a file, handles errors associated with it
*/
void	ft_close_file(int file_desc);
/*
**Opens a file, handles errors associated with it.
**If empty string is recieved as a parameter - opens STDIN
*/
int		ft_open_file(char *str);
/*
**Fills a pre-malloced string with characters that need to be printed
*/
void	ft_prepare_print_str(t_squaremap *my_map, int curr_line,
char *out_str);

#endif
