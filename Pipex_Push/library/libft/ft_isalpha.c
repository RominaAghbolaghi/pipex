/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:08:27 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/17 10:10:29 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
ctype.h header file.

Check for a alpabetic character,
it is equivalent to (ft_isupper(c) or ft_islower(c))
!!!!Even though, isalpha() takes integer as an argument, character is passed 
to the function
*/

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
