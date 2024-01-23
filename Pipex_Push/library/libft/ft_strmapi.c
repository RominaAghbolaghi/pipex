/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:36:20 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/28 11:36:24 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Applies the function ’f’ to each character of the string ’s’, and passing its 
index as first argument to create a NEW STRING (with malloc(3)) RESULTING FROM
SUCCESSIVE APPLICATIONS OF ’F’.(ft_strdup())

s: The string on which to iterate.
f: The function to apply to each character.

Return value: 
	The string created from the successive applications of ’f’.Returns NULL
if the allocation fails.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	size_t		len;
	char		*new_str;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	return (new_str);
}	
