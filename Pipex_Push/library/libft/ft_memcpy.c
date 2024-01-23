/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:04:00 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/17 11:04:06 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
<string.h> header file.

copy memory area

Copies "n" bytes from memory area of (blocks of data from) "src" with ANY TYPE 
OF DATA (VOID) to memory of "dst".
copies "n" bytes from the object(is A MEMORY LOCATION) pointed to by "src"(is 
an pointer which points to a constant value) to the object pointed to by "dest".

memcpy() simply copies n data one by one from one location to another.

The behaviour of memcpy() is undefined if:
	either "src" OR "dest" is a NULL POINTER, OR the objects 
overlap/memory overlap.
means it does not check the overlapping

 RETURNS a pointer to dest.

!!!memcpy() DOESN’T CHECK for \0 character
!!!memcpy() DOESN’T CHECK for overflow


The idea is to simply TYPECAST GIVEN ADDRESSES TO CHAR *(char takes 1 byte),
Then one by one copy data from source to destination.

!!!!!memcpy() can lose data. because of overlapping


The memory areas MUST NOT OVERLAP, Use memmove() if the memory areas do OVERLAP.
!!!memcpy() LEADS TO PROBLEMS (we dose not manage it) when source and
destination addresses overlap thats why we dont check the '\0' part. 
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
