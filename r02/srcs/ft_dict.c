#include <ft_dict.h>
#include <ft.h>

t_dict_elem			*create_dict_elem(char *key, char *value)
{
	t_dict_elem *ret;

	ret = malloc(sizeof(t_dict_elem));
	ret->key = key;
	ret->value = value;
	ret->key_len = ft_strlen(key);
	return (ret);
}