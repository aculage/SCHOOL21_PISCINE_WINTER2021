/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spilt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:33:47 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/28 20:35:15 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_s(const char *charset, char in)
{
	int cnt;

	cnt = 0;
	while (*(charset + cnt) != 0)
	{
		if (*(charset + cnt) == in)
		{
			return (1);
		}
		cnt++;
	}
	return (0);
}

int		wordcount(char *str, char *charset)
{
	int wordcount;
	int cnt;

	cnt = 1;
	wordcount = 0;
	if (!(is_s(charset, *(str + cnt - 1))))
		wordcount++;
	while (*(str + cnt) != 0)
	{
		if (!(is_s(charset, str[cnt])) && is_s(charset, str[cnt - 1]))
			wordcount++;
		cnt++;
	}
	return (wordcount);
}

void	wlengths(int *wlens, char *str, char *charset)
{
	int cnt;
	int num;
	int curlength;

	cnt = 0;
	num = 0;
	curlength = 0;
	while (*(str + cnt) != 0)
	{
		if (!(is_s(charset, str[cnt])))
			curlength++;
		if ((is_s(charset, str[cnt]) && curlength > 0))
		{
			wlens[num] = curlength;
			num++;
			curlength = 0;
		}
		cnt++;
	}
	if (curlength > 0)
		wlens[num] = curlength;
	return ;
}

void	spl(char **res, char *str, char *charset)
{
	int cnt;
	int num;
	int inncnt;

	num = 0;
	cnt = 0;
	inncnt = 0;
	while (*(str + cnt) != 0)
	{
		while (is_s(charset, *(str + cnt)) && *(str + cnt) != 0)
			cnt++;
		while (!(is_s(charset, *(str + cnt))) && *(str + cnt) != 0)
		{
			res[num][inncnt] = *(str + cnt);
			inncnt++;
			cnt++;
		}
		res[num][inncnt] = 0;
		inncnt = 0;
		num++;
	}
	if (is_s(charset, *(str + cnt - 1)))
		num--;
	res[num] = NULL;
	return ;
}

char	**ft_split(char *str, char *charset)
{
	int		wcount;
	char	**res;
	int		*wlens;
	int		n;

	n = 0;
	wcount = wordcount(str, charset);
	res = (char **)malloc(sizeof(char *) * (wcount + 1));
	wlens = (int *)malloc(sizeof(int *) * wcount);
	wlengths(wlens, str, charset);
	while (n < wcount)
	{
		res[n] = (char *)malloc(sizeof(char) * (wlens[n] + 1));
		n++;
	}
	spl(res, str, charset);
	return (res);
}
