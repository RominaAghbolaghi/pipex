/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:42:06 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/17 17:42:12 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
<ctype.h> header file

If  c  is a uppercase letter, tolower() returns its lowercase equivalent,if an
lowercase representation exists in the current locale Otherwise, it returns c.

 If c is neither an unsigned char value nor EOF, the behavior of these functions 
is undefined.
*/

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}
