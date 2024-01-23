/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:57:23 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/25 15:57:28 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
s1: The string to be trimmed.(pirayesh kardan)
set: The reference set of characters to trim.

Allocates (with malloc(3)) and returns a copy of 's1’ (strlcpy) with tHE
CHARACTERS SPECIFIED IN ’SET’ (ft_strchr(s1)) removed from the beginning and
the end of the string.

char	*ft_strchr(const char *s, int c)
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)

Return value: The trimmed string. NULL if the allocation fails.
#32 to avoid of craching
#39 already we started from the begining of string thats why we need to cmp
end with the start
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	str = NULL;
	if (s1 && set)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
			end--;
		str = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, &s1[start], end - start + 1);
	}
	return (str);
}
