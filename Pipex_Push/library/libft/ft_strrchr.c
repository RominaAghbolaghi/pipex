/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:58:15 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/17 17:58:18 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 <string.h> header file

returns a pointer to THE LAST OCCURRENCE of the character c in the string s.

Here "character" means "byte"; these functions do not work with wide or 
multibyte characters(french, japonese...).

return a pointer to the matched character or NULL if the character is  not
found.
 
The  terminating  null byte is considered part of the string, so that 
IF C IS SPECIFIED AS '\0', these functions return a pointer to the TERMINATOR
'\0'.thats why we compare '\0' PART OF STRING S[FT_STRLEN(S)] with c #37,38. 
*/

char	*ft_strrchr(const char *s, int c)
{	
	unsigned char	ch;
	int				i;

	i = 0;
	ch = (unsigned char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
