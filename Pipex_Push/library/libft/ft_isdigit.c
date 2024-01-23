/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_isdigit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:20:24 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/14 13:24:24 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
ctype.h header file

Check for a digit (0 through 9)

!!!!!Even though, isdigit() takes integer as an parameter, character is passed 
to the function as an argument.
Internally, the character is converted to its ASCII value for the check.
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
