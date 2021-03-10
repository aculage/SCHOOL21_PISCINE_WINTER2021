/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:00:13 by hbrendon          #+#    #+#             */
/*   Updated: 2021/02/20 20:45:32 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		isalphanumeric(const char *sym)
{
	if (*sym >= 48 && *sym <= 57)
	{
		return (1);
	}
	if (*sym >= 65 && *sym <= 90)
	{
		return (2);
	}
	if (*sym >= 97 && *sym <= 122)
	{
		return (3);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char *ret;
	char prev_type;

	ret = str;
	prev_type = 0;
	while (*str != 0)
	{
		if (isalphanumeric(str) > 0)
		{
			if (isalphanumeric(str) == 3 && prev_type == 0)
			{
				*str -= 32;
			}
		}
		prev_type = isalphanumeric(str);
		str++;
	}
	return (ret);
}
