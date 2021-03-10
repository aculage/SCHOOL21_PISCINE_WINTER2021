/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrendon <hbrendon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:03:23 by hbrendon          #+#    #+#             */
/*   Updated: 2021/03/07 13:49:26 by hbrendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

/*Creates an element of a list. Should not be used by itself,	*/
/*see ft_sorted_list_insert										*/
t_list				*ft_create_elem(void *data);
/*Inserts elements into the list.								*/
/*Obeys sorting by comparator function passed as an argument.	*/
void				ft_sorted_list_insert(t_list **begin_list,
void *data, int (*cmp)());
/*Sorts list. TO BE DEPRECATED									*/
void				ft_list_sort(t_list **begin_list, int (*cmp)());
/*Pushes element to the front of the list. TO BE DEPRECATED		*/
void				ft_list_push_front(t_list **begin_list, void *data);
#endif