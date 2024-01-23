/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:58:29 by rmohamma          #+#    #+#             */
/*   Updated: 2022/12/05 11:58:32 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DELETES AND FREES the given node and every successor of that node, using the
function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL

lst: The address of a pointer to a node.
del: The address of the function used to delete the content of the node.

External functs. free
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*templ;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		templ = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = templ;
	}
}
