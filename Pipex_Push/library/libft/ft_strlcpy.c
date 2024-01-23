/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:01:54 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/17 13:01:59 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
<string.h> header file.

size-bounded (size is bounded(karandar) within a predefined threshold(sarhad)) 
string copying.

!!strlcpy() >>> copy up to strlen(src) numbers to dst and will not write more 
than dstsize many bytes

Copies up to <size-1> (sizeof(dst) - 1) characters (excluded the null)(a byte 
for the NUL should be included in "size") from the NUL-terminated string src 
to the NUL-terminated dst(only operate on TRUE “C” STRINGS.both src and dst 
must be NUL-terminated.)

take the full size of the destination string (buffer size == sizeof(dst)) as
a size parameter not just the length .

guarantee that the destination string is null terminated (as long as size is 
larger than 0)for all nonzero-length buffers.

return 
the total length of the string (strlen()) they tried to create, that is
SIMPLY THE LENGTH OF THE SOURCE. 

it was done to make truncation detection simple.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
