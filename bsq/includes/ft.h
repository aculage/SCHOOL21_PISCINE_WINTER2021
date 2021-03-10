#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include "ft_error.h"
/*
**Appends *appendix to *str. *str is reallocated to len(str) + resize
*/
char	*ft_strappend(char *str, char *appendix, int resize);
/*
**Returns length of a string terminated by term
*/
int		ft_strlen(char *str);
/*
**Converts str to int
*/
int		ft_atoi(char *str);
/*
**Reallocates buffer buf and resizes it to nsize, frees the initial buffer
**backshift is used to free a buf, if not the start of it was passed
*/
char	*ft_realloc(char *buf, int bsize, int nsize, int backshift);
/*
**Locates '\\n' in buffer. If no located, returns -1
*/
int		locnewln(char *buf, int size);
/*
**Sets rules which symbols should be displayed in the map
*/
void	ft_setsymb(char *symb, char *str);
#endif
