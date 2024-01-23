/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:31:24 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/18 12:31:29 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
<string.h> header file>

returns a POINTER to a NEW STRING which is a duplicate of the string 's'. 

Memory for the new string is obtained with MALLOC(3)(in the heap), so we need 
to secure our malloc and can be freed with free(3) if WE FREE THE MEMORY our 
pointer will be DINGLING so hear IT IS NOT LOGIC TO FREE THE MEMORY IN THE 
FUNCTION.

It returns NULL if INSUFFICIENT MEMORY was available, with errno set to 
indicate the cause of the error.
*/
char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*s2;

	i = 0;
	size = ft_strlen(s);
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
