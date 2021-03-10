#include <ft_fparser.h>

char 	*get_string(char **buffs, int bufnum, int lbuffoffset)
{
	char *retstr;
	int cnt;
	int cntbuf;
	int strptr;

	strptr = 0;
	retstr = malloc(bufnum * 4096 + lbuffoffset + 1);
	cnt = 0;
	cntbuf = 0;
	while (cnt < 4096 && cntbuf < bufnum)
	{
		retstr[strptr] = buffs[cntbuf][cnt];
	}
}

int 	crtnewbuf(char **buffs, int *bufnum, int *offs)
{
	(*bufnum)++;
	if (buffs[*bufnum] == NULL)
	{
		buffs[*bufnum] = malloc(4096);
		if (buffs[*bufnum] == NULL)
		{
			ft_putstr(2, "Memory allocation failed");
			return ;
		}
		*offs = 0;
	}
	else
		*offs = 0;
}

void	parsedict(int file, t_list *dict)
{
	char **buffs;
	int offs;
	int bufnum;
	int bufnummax;

	buffs[0] = malloc(4096);
	bufnum = 0;
	if (buffs[bufnum] != NULL)
	{
		read(file, buffs, 4096);
		while (*(buffs[bufnum] + offs) != '\n')
		{
			offs++;
			if (offs == 4096)
				crtnewbuf(buffs, &bufnum, &offs);
		}
		get_string(buffs, bufnum, offs); 
	}
}
