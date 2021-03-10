/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:58:54 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/07 14:07:25 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
/*Prints a string to the passed stream*/
void	ft_putstr(int stream, char *str);
/*Returns length of a string*/
int		ft_strlen(char *str);
/*Compares two strings. Returns ASCII			*/
/*difference between two differing values 		*/
/*of type int, or zero if strings don`t differ	*/
int		ft_strcmp(char *s1, char *s2);

#endif
