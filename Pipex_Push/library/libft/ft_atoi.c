/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:41:33 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/18 11:41:51 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

<stdlib.h> header file.

It is generally used if we have to perform mathematical operations on 
the string which contains a number.
Whenever we receive data from TextField or TextArea, entered data is 
received as a string. 
If entered data is in number format, we need to convert the string to
an int. To do so, we use atoi() method.

DESCRIPTION
    converts THE INITIAL PORTION OF THE STRING pointed to by nptr to int. 
The string may begin with an arbitrary amount of WHITE SPACE #48 followed by 
A SINGLE optional '+'  or  '-' sign (if we have two signs we will stop to 
converting thats why we use "if" not while).The remainder of the string is 
converted to an int value in the obvious manner, stopping at THE FIRST CHARACTER
The function stops reading the input string at the first character that it 
cannot recognize AS PART OF A NUMBER.

!!atoi() does like strtol() but atoi() dose not detect errors.

RETURN VALUE
    The converted value.
*/
long int	ft_atoi(const char *nptr)
{
	long int	result;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\t' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
