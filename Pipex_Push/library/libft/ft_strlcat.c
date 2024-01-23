/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:42:04 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/17 15:42:09 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
<bsd/string.h> header file.

appends the NUL-terminated string src tO THE END OF the NUL-terminated dst
(!=dest).It will append at most <<SIZE - STRLEN(DST) - 1>> bytes from src, the
result is NUL-terminating.(only operate on true “C” strings. both src and dst 
must be NUL-terminated.)

take the FULL SIZE OF the destination string (buffer) as a size parameter
(not just the length).equal to its buffer size

guarantee that the destination string is null terminated (as long as there 
is at least one byte free in dst)for all nonzero-length buffers.

return
 the TOTAL LENGTH OF THE STRING THEY TRIED TO CREATE.


accept the FULL SIZE OF THE DESTINATION string as a size parameter.
take the fULL SIZE OF THE BUFFER(not just the length).
 we count the dest size untile before reach the size
guarantee that the destination string is null terminated for all
nonzero-length buffers.

return the total length of the STRING it tried to create,
that means the INITIAL LENGTH OF DST plus the LENGTH OF SRC.

?it was done to make truncation detection simple.


strlcat() appends string src to the end of dst. It will append at most 
DSTSIZE – STRLEN(DST) – 1 characters. It will then NUL-terminate, 
unless dlen is 0 or the original dst string was longer than dstsize 
(in practice this should not happen as it means that either dstsize is 
incorrect or that dst is not a proper string).

if strlcat() traverses size characters without finding a NUL / '\0', 
the length of the string is considered to be size and the destination
string will not be NUL-terminated (since there was no space for the NUL).
This keeps strlcat() from running off the end of a string.  In practice this 
should not happen (as it means that either size is incorrect or that dst is 
not a proper “C” string).  The check exists to prevent potential security 
problems in incorrect code.

vaghti ke buffer size ma 0 hastesh be in mani nist ke dest ma null pointerhast
hastesh 
#81 age size ma bozorgtar az dst length bashe unvaght mire ta az src 
copy kone tu dest yani ezafe mikone be entehaye dst va dar in sharayet ma
motmaenim ke \0 khahim dasht dar dest vase hamine ke tu sharte while 
dsize < size -1 darim

#88 return(0) niz unit ro pass mikone chon fekr konam vaghti size ma 0 hastesh 
aslan hesab nemikone

ex: https://c-for-dummies.com/blog/?p=3896
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	f_dlen;
	size_t	dlen;

	f_dlen = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[f_dlen] && f_dlen < size)
		f_dlen++;
	dlen = f_dlen;
	while (src[dlen - f_dlen] && dlen < size - 1)
	{
		dest[dlen] = src[dlen - f_dlen];
		dlen++;
	}
	if (f_dlen < size)
		dest[dlen] = '\0';
	return (f_dlen + ft_strlen(src));
}
