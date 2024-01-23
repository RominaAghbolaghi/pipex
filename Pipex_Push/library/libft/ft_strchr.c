/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:57:56 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/17 17:57:59 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 <string.h> header file

returns a pointer to the first occurrence of the character c in the string s.

Here "character" means "byte"; these functions do not work with wide or 
multibyte characters(france, japon...).

return a pointer to the matched character or NULL (NULL is a pointer) if the 
character is not found. 

The  terminating  null byte is considered part of the string, so that 
if c is specified as '\0', these functions return a pointer to the terminator.
*/

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*s && (*s != ch))
		s++;
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}
