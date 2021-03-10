/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:58:41 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/09 23:22:26 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H
# ifndef BUFSIZE
#  define BUFSIZE 10000
# endif
# ifndef LKERRNO
#  define LKERRNO 0
# endif
# ifndef FMISSING
#  define FMISSING 1
# endif
# ifndef TMNYARGS
#  define TMNYARGS 2
# endif
# ifndef CNNTRDFILE
#  define CNNTRDFILE 2
# endif

void	errhandle(int errid);
void	read_f(int stream, char *buffer, int size);
void	print(int stream, char *buffer, int size);
#endif
