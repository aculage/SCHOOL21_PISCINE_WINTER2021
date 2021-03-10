#include <ft_list.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*s;
	t_list	*lcl;

	lcl = *begin_list;
	if (lcl == NULL)
		return ;
	while (((lcl)->next) != NULL)
	{
		if (cmp((lcl)->next->data, data) > 0)
		{
			s = (lcl)->next;
			(lcl)->next = ft_create_elem(data);
			(lcl)->next->next = s;
		}
		(lcl) = (lcl)->next;
	}
}


void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*ptr1;
	t_list	*ptr2;
	void	*swpdata;

	ptr1 = (*begin_list);
	ptr2 = (*begin_list);
	if (ptr1 == NULL)
		return ;
	while (ptr1 != NULL)
	{
		while (ptr2 != NULL)
		{
			if (cmp(ptr1->data, ptr2->data) > 0)
			{
				swpdata = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = swpdata;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr1;
	}
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *curr;

	if (begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	curr = ft_create_elem(data);
	curr->next = (*begin_list);
	*begin_list = curr;
}

t_list	*ft_create_elem(void *data)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	ret->data = data;
	ret->next = NULL;
	return (ret);
}
