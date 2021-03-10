#ifndef FT_DICT_H
# define FT_DICT_H
# include <stdlib.h>

typedef struct		s_dict_elem
{
	char	*key;
	char	*value;
	int		key_len;
}					t_dict_elem;
/*Creates a dict element from a pair of (key, value). Preserves length of (key)*/
t_dict_elem			*create_dict_elem(char *key, char *value);
#endif