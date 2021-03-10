#include "skyscrapers.h"
#include "ft.h"
#include <stdio.h>

void	lrchck41(t_field *infi, const t_initsquare *sq, const int size)
{
	int cnt;
	int cnt1;

	cnt = 0;
	while (cnt++ < size)
	{
		if (sq->r_border[cnt - 1] == 4 && sq->l_border[cnt - 1] == 1)
		{
			cnt1 = 0;
			while(cnt1++ < size)
				infi->field[size * (cnt - 1) + cnt1 - 1] = size - cnt1 + 1;
	
		}
		if (sq->r_border[cnt - 1]++ == 1 && sq->l_border[cnt] == 4)
		{
			cnt1 = 0;
			while(cnt1 < size)
				infi->field[size * (cnt - 1) + cnt1 - 1] = cnt1 - 1;
		}
	}
}

void	lrchck1(t_field *infi, const t_initsquare *sq, const int size)
{
	int cnt;
	int cnt1;

	cnt = 0;
	while (cnt++ < size)
	{
		if (sq->l_border[cnt - 1] == 1)
		{
			infi->field[size * (cnt - 1)] = 4;
		}
		if (sq->r_border[cnt - 1] == 1)
		{
			infi->field[size * (cnt - 1) - 1] = 4;
		}
	}
}

void	call(t_field *infi, const t_initsquare *sq, const int size)
{
	lrchck1(infi, sq, size);
	lrchck41(infi, sq, size);
}