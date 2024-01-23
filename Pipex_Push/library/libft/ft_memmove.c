/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:12:14 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/17 11:12:19 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
<string.h> header file.

Copies "n" bytes from MEMORY AREA of (blocks of data from) "src" with ANY 
TYPE OF DATA (VOID) to memory of "dst".

!!!!Copying is performed even if the "src" and "dest" pointer OVERLAPS. 
This is because memmove() COPIES THE DATA FIRST TO AN INTERMEDIATE BUFFER,
then FROM THE BUFFER TO DESTINATION.(but it makes alot of overlap in unit test) 

!!!THE ALGORITHM IS INEFFICIENT (AND HONESTLY DOUBLE THE TIME IF YOU USE A 
TEMPORARY ARRAY). DOUBLE COPIES SHOULD BE AVOIDED UNLESS IF IT IS REALLY 
IMPOSSIBLE. 

what the memmove() library function does: By COMPARING the src and the dst 
ADDRESSES you should be able to FIND IF THEY OVERLAP.
	1.If they do not overlap, you can copy in any direction.
	2If they do overlap, find WHICH END OF DEST overlaps with the source 
and choose the direction of copy accordingly:

	2-1.If the BEGINNING OF DEST overlaps #55, COPY FROM END TO BEGINNING 
	2-2.If the END OF DEST OVERLAPS, copy FROM BEGINNING TO END
	2-3.Another optimization would be to COPY BY WORD SIZE
	JUST BE CAREFUL TO HANDLE THE BOUNDARY CONDITIONS. 
	2-4. A further optimization would be to use vector instructions for the 
copy since they’re contiguous.

 RETURNS dest, the pointer to the destination memory location.

!!!!!with memmove function whenever overlap happens then the pointer will 
start to print from the beginning, but with memcpy function, it just ignores
if there is an overlap and just keep moving forward.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
