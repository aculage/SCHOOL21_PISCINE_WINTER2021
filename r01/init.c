#include "skyscrapers.h"
#include "ft.h"
#include "stdlib.h"
#include <stdio.h>






t_initsquare	*generate_initsquare(const char *st, int *size)
{
	t_initsquare	*ret;
	int 			cnt;
	
	cnt = 0;
	*size = (ft_strlen(st) + 1) / 2 / 4;
	ret = (t_initsquare *)malloc(sizeof(t_initsquare) );
	ret->l_border = (int *)malloc(sizeof(int) * (*size + 1));
	ret->b_border = (int *)malloc(sizeof(int) * (*size + 1));
	ret->t_border = (int *)malloc(sizeof(int) * (*size + 1));
	ret->r_border = (int *)malloc(sizeof(int) * (*size + 1));
	printf("%ld\n",sizeof(t_initsquare));
	while (cnt < *size)
	{
		ret->t_border[cnt] = st[2 * cnt] - 48;
		ret->b_border[cnt] = st[2 * *size + 2 * cnt] - 48;
		ret->l_border[cnt] = st[2 * (2 * *size) + (2 * cnt)] - 48;
		ret->r_border[cnt] = st[3 * (2 * *size) + (2 * cnt)] - 48;
		cnt++;
	}
	cnt = 0;
	printf("%p %p %p %p %p\n", ret, ret->l_border, ret->t_border, ret->b_border, ret->r_border);
	while (cnt < *size )
	{
		printf("%d %d %d %d\n", ret->l_border[cnt], ret->t_border[cnt], ret->b_border[cnt], ret->r_border[cnt]);
		cnt++;
	}
	return (ret);	
}

t_field			*generate_field(const int size)
{
	t_field	*ret;
	int cnt;
	
	cnt = 0;
	ret->field = (int *)malloc(sizeof(int) * size * size);
	if (ret->field == NULL)
	{	write(1, "Error", 5);
		return(NULL);
	}
	while (cnt++ < size * size)
		*(ret->field + cnt - 1) = 0;
	return (ret);
}