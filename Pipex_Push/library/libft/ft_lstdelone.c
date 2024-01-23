/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:42:35 by rmohamma          #+#    #+#             */
/*   Updated: 2022/12/05 11:42:38 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Takes as a parameter a node and FREES THE MEMORY of THE NODE’S CONTENT using 
THE FUNCTION ’DEL’ given as a parameter and FREE THE NODE (free()). THE MEMORY
OF ’NEXT’ MUST NOT BE FREED.(thats why we transfer only content of the lst)

lst: The node to free.
del: The address of the function used to delete the content.
External functs: free
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
