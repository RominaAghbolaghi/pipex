/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:49:42 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/18 09:49:51 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
<bsd/string.h> header file

locates the first occurrence of the null-terminated string "little" in the 
string "big", where not more than "len" characters are searched. Characters that
appear after a ‘\0’ character are not searched.

!!!!!we dont use malloc

If little is an empty string #38(is different from null sting), big is returned;
if little occurs nowhere in big #32,50 NULL is returned; otherwise a pointer to 
the first character of the first occurrence of little is returned #36.

# null pointer with 0 len to search
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big && len == 0)
		return (NULL);
	if (!little[0])
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (little[j] && (big[i + j] == little[j]) && i + j < len)
			{
				if (little[j + 1] == '\0')
					return ((char *)&big[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
