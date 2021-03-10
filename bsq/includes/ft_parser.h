#ifndef FT_PARSER_H
# define FT_PARSER_H
# include "ft_bsq.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
#include <unistd.h>

/*
**Parses file into a structure
*/
t_squaremap		*parsefile(char *path);
/*
**Generates initial state of the structure: col_num, symb
*/
void			initgen(int file, t_squaremap *ret);
/*
**Validates map. sets its pointer to NULL if map is invalid
*/
int				ft_validate(t_squaremap *map);
/*
**Creates a row of the map
*/
void			createrow(t_squaremap *sqmap, int rownum, char *buffer,
int size);
/*
**Sets three symbols. STUD function
*/
void			ft_setsymb(char *symb, char *str);
/*
**Reads fixed sized buffers into t_squaremap *sqmap
*/
void			readrest(t_squaremap *sqmap, int file, char *buf, int pos);
/*
**Sets initial value to a struct. STUD function
*/
void			setinitvals(t_squaremap *ret, char *str);
/*
**Reads and interprets first string of map
*/
void			getfirststr(int file, char *buf, char **str);
/*
**Reads first row of the map
*/
int				getfirstmaprow(int *pos, int file, int *size, char **buf);
/*
**Stud function for getting good result for 1 row
*/
int				getresforone(int netread, t_squaremap *sqmap, int pos);
#endif
