/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:35:19 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/14 14:46:59 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
<string.h> header file.

calculates the length of a given string, pointed by s, excluding
the terminating null byte ('\0') means the null character doesn't count.

The returned value is of type size_t (an unsigned integer type).
LIBRARY FUNCTIONS that TAKE OR RETURN SIZES expect them to be of type or have 
the return type of size_t.

"char *ptr" ptr is a pointer to char, i.e. both can be change here. "const 
char *ptr" ptr is a pointer to const char i.e. pointer can change but not char.
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
