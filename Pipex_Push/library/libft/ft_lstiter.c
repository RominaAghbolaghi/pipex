/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:14:38 by rmohamma          #+#    #+#             */
/*   Updated: 2022/12/05 12:14:41 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Iterates the list (going through each element of the list individually) ’lst’ 
and applies the function ’f’ on the content of each node.

lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{	
		f(lst->content);
		lst = lst->next;
	}
}
