/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:31:23 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/25 14:41:07 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*A substring is itself a string that is part of a longer string.
For example, substrings of string "the" are "(empty string)"#39 ( so if our 
strlen is less than position of start our result will be empty string memory
allocated but they dont have any element in it),"t", "th", "the", "h", "he" 
and "e".

The substring begins at index ’start’ and is of maximum size ’len’. so we need
to find the correct size of len.

Return value: 
The substring (so we need malloc or calloc) or NULL if the allocation fails 
(when we dont have any string as an input.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			s_len;
	size_t			size;
	char			*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len - 1 < start)
		size = 0;
	else if (len >= s_len - start)
		size = s_len - start;
	else
		size = len;
	substr = (char *)ft_calloc((size + 1), sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[i] && i < size)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}
