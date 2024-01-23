/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:58:47 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/17 11:03:16 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
<string.h> header file.

Erases the data in the "n" bytes of THE MEMORY STARTING AT THE LOCATION pointed
 by "s", by writing ZEROS BYTES (containing '\0') to that area.
 copies "n" bytes, each with a value of zero, into STRING "s"(thats why we 
convert the data type).
*/

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
