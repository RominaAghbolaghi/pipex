/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:53:01 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/18 11:53:06 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
<stdlib.h> header file.

The name "calloc" stands for contiguous(nearby, beside) allocation.

calloc() function allocates memory for AN ARRAY of "NMEMB" ELEMENTS of "SIZE" 
BYTES EACH and RETURNS A POINTER to the allocated memory.  THE MEMORY IS SET 
TO ZERO.

The malloc() function allocates memory and LEAVES THE MEMORY UNINITIALIZED, 
whereas the calloc() function allocates memory and INITIALIZES ALL BITS TO ZERO.


RETURN:
return a POINTER to the allocated memory, which is suitably aligned for any
built-in type. 
On error, these functions return NULL,  
If (nmemb * size) would result in INTEGER OVERFLOW #50,[detecting overflow:
if (size != 0 && (size * nmemb) / size != nmemb) ] then calloc() returns 
an error. for handling error we return NULL.

In computer programming, an INTEGER OVERFLOW occurs when an arithmetic operation 
attempts to create a numeric value that is outside of the range that can be 
represented with a given number of digits – either higher than the maximum or 
lower than the minimum representable value.

If nmemb or size is 0 #53, then calloc() returns either NULL. 

#53 i dont convert the memory allocated to char because return type is void

NULL may also be returned by a successful call to calloc() with "nmemb" or 
"nmemb" equal to zero.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*s;

	if (size != 0 && (size * nmemb) / size != nmemb)
		return (NULL);
	s = malloc(nmemb * size);
	if (!nmemb || !size)
		return (s);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}
