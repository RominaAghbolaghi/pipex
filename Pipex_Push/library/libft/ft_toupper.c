/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:41:40 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/17 17:41:45 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
<ctype.h> header file

If  c  is a lowercase letter, toupper() returns its uppercase equivalent, if an
 uppercase representation exists in the current locale.  Otherwise, it returns c.

 If c is neither an unsigned char value nor EOF, the behavior of these functions 
is undefined.
*/

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
