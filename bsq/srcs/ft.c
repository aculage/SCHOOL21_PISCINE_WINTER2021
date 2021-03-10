#include "ft.h"
#include <stdio.h> //TODO:REMOVE

extern int g_errnum;

int		ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (*(str + cnt) != 0)
	{
		cnt++;
	}
	return (cnt);
}

char	*ft_strappend(char *str, char *appendix, int resize)
{
	char	*ret;
	int		cnt;
	int		cnt2;

	cnt = 0;
	ret = (char *)malloc(ft_strlen(str) + resize + 1);
	while (*(str + cnt) != 0)
	{
		*(ret + cnt) = *(str + cnt);
		cnt++;
	}
	cnt2 = 0;
	while (*(appendix + cnt2) != 0)
	{
		*(ret + cnt) = *(appendix + cnt2);
		cnt++;
		cnt2++;
	}
	*(ret + cnt) = 0;
	free(str);
	return (ret);
}

int		ft_atoi(char *str)
{
	int ret;
	int shift;

	ret = 0;
	shift = 0;
	while ((*(str + shift) >= 48 && *(str + shift) <= 57) &&
	(*(str + shift) != 0))
	{
		ret *= 10;
		ret += (*(str + shift) - 48);
		shift++;
	}
	if (*(str + shift) != 0 || ft_strlen(str) == 0)
		ret = -1;
	return (ret);
}

char	*ft_realloc(char *buf, int bsize, int nsize, int backshift)
{
	char	*ret;
	int		cnt;

	cnt = 0;
	ret = (char *)malloc(sizeof(char) * nsize);
	if (ret == NULL)
		g_errnum = MEMALLOCERR;
	while (cnt < bsize)
	{
		ret[cnt] = buf[cnt];
		cnt++;
	}
	free(buf - backshift);
	return (ret);
}

int		locnewln(char *buf, int size)
{
	int cnt;

	cnt = 0;
	while (cnt < size && buf[cnt] != '\n')
		cnt++;
	if (cnt == size)
		return (-1);
	return (cnt);
}
