#include "skyscrapers.h"
#include "ft.h"
#include <stdio.h>







int main (int argc, char **argv)
{
	t_field 		*f;
	t_initsquare 	*sq;
	int 			sz;
	int 			cnt;

	cnt = 0;
    if (argc != 2)
	{
		write(1, "Error", 5);
		return(0);
	}
	sq = generate_initsquare(*(argv + 1), &sz);
	printf("%p %p %p %p %p\n", sq, sq->l_border, sq->t_border, sq->b_border, sq->r_border);
	cnt = 0;
	while (cnt < sz )
	{
		printf("%d %d %d %d\n", sq->l_border[cnt], sq->t_border[cnt], sq->b_border[cnt], sq->r_border[cnt]);
		cnt++;
	}
	f = generate_field(sz);
	
	//call(f,sq,sz);
	printf("%p %p %p %p %p\n", sq, sq->l_border, sq->t_border, sq->b_border, sq->r_border);
	cnt = 0;
	while (cnt < sz * sz)
	{
		printf("%d ", f->field[cnt]);
		if (cnt % sz == sz - 1)
			printf("\n");		
		cnt++;	
	}
    
}