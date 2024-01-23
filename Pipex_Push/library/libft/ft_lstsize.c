/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:19:37 by rmohamma          #+#    #+#             */
/*   Updated: 2022/12/05 11:19:41 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Counts the number of nodes in a list.

lst: The beginning of the list.
Return value: The length of the list
*/

int	ft_lstsize(t_list *lst)
{
	int	node_num;

	node_num = 0;
	while (lst)
	{
		node_num++;
		lst = lst->next;
	}
	return (node_num);
}
