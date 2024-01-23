/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:26:50 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/25 17:26:55 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
s: The string to be split(do nim kardan).
c: The delimiter(hael) character

Allocates (with malloc(3)) and returns an ARRAY OF STRINGS (array of pointers,
 poinetr to pointers for saving the memory) obtained by splitting ’s’ array 
using the character ’c’ as a delimiter. The array must end with a NULL POINTER.

Return value: 
The array of new strings resulting from the split. NULL if the allocation fails

!!!The continue statement in C language is used to bring the program control 
to the beginning of the loop. 

i divide s to 3parts first part if s start with delimiter, second part string 
part which start with letter and last part if end with delimiter

#67 we check if our first part strat with delimiter or not if it start we ignore 
it and we pass to next element (first part)

!(in second part)when i reach the delimiter i count a new pointer #82
#73,75 for avoiding increment of i for the second time if we exited from the 
internal while we need to continue statement 
if we dont have continue it will pass to next element but we already passed 
in the while loop so to avoid that we write continue

#77 i check if our last character is delimiter or not because i need to count 
last str as a new pointer (last part)
 we reach to delimiter and we count our first word which was behind the
delimiter so when our last character is not delimiter so we need to count our 
actual word as a new word

#133 function calls PASS BY POINTER;i want TO MODIFY THE ARGUMENT VALUE IN THE 
CALLING FUNCTION (changing ptr adr for next ptr and have the ptr_len through the
function)

#100 our free function free the memory for pointer to pointer so thats why it 
returns pinter to pointer
		size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
*/

static size_t	ft_nb_ptr(char const *s, char c)
{
	size_t	i;
	size_t	nb_ptr;

	if (!s[0])
		return (0);
	i = 0;
	nb_ptr = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_ptr++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_ptr++;
	return (nb_ptr);
}

static void	get_ptr(char **ptr, size_t *ptr_len, char c)
{
	size_t	i;

	*ptr += *ptr_len;
	*ptr_len = 0;
	i = 0;
	while (**ptr && **ptr == c)
		(*ptr)++;
	while ((*ptr)[i])
	{
		if ((*ptr)[i] == c)
			return ;
		(*ptr_len)++;
		i++;
	}
}

static char	**free_malloc(char **ptr_ptr)
{
	size_t	i;

	i = 0;
	while (ptr_ptr[i])
	{
		free(ptr_ptr[i]);
		i++;
	}
	free(ptr_ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_ptr;
	char	*ptr;
	size_t	ptr_len;
	size_t	i;
	size_t	nb_ptr;

	if (!s)
		return (NULL);
	nb_ptr = ft_nb_ptr(s, c);
	ptr_ptr = (char **)ft_calloc((nb_ptr + 1), sizeof(char *));
	if (!ptr_ptr)
		return (NULL);
	i = 0;
	ptr = (char *)s;
	ptr_len = 0;
	while (i < nb_ptr)
	{
		get_ptr(&ptr, &ptr_len, c);
		ptr_ptr[i] = (char *)malloc(sizeof(char) * (ptr_len + 1));
		if (!ptr_ptr[i])
			return (free_malloc(ptr_ptr));
		ft_strlcpy(ptr_ptr[i], ptr, ptr_len + 1);
		i++;
	}
	return (ptr_ptr);
}
