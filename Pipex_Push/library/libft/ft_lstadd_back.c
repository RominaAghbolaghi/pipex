/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:34:40 by rmohamma          #+#    #+#             */
/*   Updated: 2022/12/05 11:34:44 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Adds the node ’new’ at the end of the list.

lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*templ;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	templ = ft_lstlast(*lst);
	templ->next = new;
	return ;
}
