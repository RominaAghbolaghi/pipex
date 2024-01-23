/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:42:54 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/17 10:53:42 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
<string> header file.

it is used to FILL THE MEMORY BLOCKS with a PARTICULAR VALUE.
Fill with "n" bytes of "c" the memory of "s".
It will copy "n" blocks of the "s" with "c".
 s ==> STARTING ADDRESS of memory to be filled
 c ==> Value to be filled
 n ==> Number of bytes to be filled from the first address of "s" to be filled

"s" is A VOID POINTER, so that we can pass any type of pointer to this function.
!!!UNSIGNED CHAR must be used for ACCESSING MEMORY AS A BLOCK OF BYTES

The character represented by "c" (library functions take the chars as integer) 
is first converted to unsigned char and then copies it into the first "n" 
characters of the object pointed to by "s".


The behaviour of the function is undefined if: 
	"len" is greater than the size of "s".
!!means it dose not check the n and s size.

returns:
 a pointer to the memory area "s", so you should return THE ORIGINAL POINTER 
returns "s".from the called function, you're actually changing the contents of 
the memory locations.A variable declared in a function can not be used in main

memset HAVE TO TRUST THE LENGTH that is passed in. memset needs to work on a
general piece of memory,not just a 0/NULL terminated string.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
