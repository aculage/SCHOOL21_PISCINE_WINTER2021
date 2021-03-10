/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:39:09 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/21 20:02:07 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	racer(int *fs, int sshift, char **str, char **tf)
{
	*fs = 0;
	while ((*(*str + sshift) == *(*tf + *fs)) && (*(*tf + *fs) != 0))
	{
		sshift++;
		*fs = *fs + 1;
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	int	sshift;
	int	fs;

	if (*to_find == 0)
	{
		return (str);
	}
	sshift = 0;
	fs = 0;
	while (*(str + sshift) != 0)
	{
		if (*(str + sshift) == *to_find)
		{
			racer(&fs, sshift, &str, &to_find);
			if (*(to_find + fs) == 0)
			{
				return (str + sshift);
			}
		}
		sshift++;
	}
	return ((void*)0);
}
