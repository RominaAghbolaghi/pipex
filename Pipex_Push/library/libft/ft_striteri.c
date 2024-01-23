/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:22:37 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/28 14:22:42 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Applies THE FUNCTION ’f’ on each character of the string passed as argument, 
passing ITS INDEX AS FIRST ARGUMENT (unsigned int in f). EACH CHARACTER (char*)
as pointer is passed BY ADDRESS TO ’f’ to be modified if necessary.

Parameters: 
lst: The string on which to iterate.
f: The function to apply to each character.

Return value: :None
*/
void	ft_striteri(char *lst, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (lst && f)
	{
		while (lst[i])
		{
			f(i, &lst[i]);
			i++;
		}
	}
	return ;
}
