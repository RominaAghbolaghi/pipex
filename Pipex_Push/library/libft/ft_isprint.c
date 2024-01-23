/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:10:14 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/14 14:14:27 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
ctype.h header file.

Checks for any printable character INCLUDING SPACE, Printable characters are 
just the opposite of control characters which can be checked using iscntrl().

!!!!!Even though, isascii() takes integer as an argument, but character is 
passed to the function.
Internally, the character is converted to its ASCII value for the check.
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
