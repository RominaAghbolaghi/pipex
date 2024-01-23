/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:57:23 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/18 08:57:27 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
string.h> header file.

it compares only the first (at most) n bytes of the two strings s1 and s2.
The comparison is done using unsigned characters.

return an integer less than, equal to, or greater than zero if the first n bytes 
thereof is found, respectively, to be less than, to match, or be greater than s2.

The strcmp() function is similar, except it compares the two strings s1 and s2.

char *p;
p = "hello";

---->  *p >> h
----> (*++p) = *(++p) // value of ++p is p after the increment >> e
----> (*p++) = (*p)++  // value of p++ is p before the increment >> e

1) Post-Increment (i++): we use i++ in our statement if we want to use the 
current value, and then we want to increment the value of i by 1.

2) Pre-Increment(++i): We use ++i in our statement if we want to increment the 
value of i by 1 and then use it in our statement.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
		if (*s1++ != *s2++)
			return ((unsigned char)*--s1 - (unsigned char)*--s2);
	return (0);
}
