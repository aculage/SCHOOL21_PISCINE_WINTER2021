/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:58:41 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/01 21:06:18 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H
# ifndef BUFSIZE
#  define BUFSIZE 4097
# endif

void	errhandle(char **argv, int strnum);
int		read_f(int stream, char *buffer, int size);
void	print(int stream, char *buffer, int size);
int		ft_display_file(char *path, int file, char **argv, int strnum);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

#endif
