/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:32:15 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/28 10:32:20 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Allocates (with malloc(3)) and returns a string representing the integer 
(coverts the integer n into a character string) received as an argument.
!!!!Negative numbers must be handled. (we count the num of digit and after that
we cheeck if our num is negative or positive. if is negative we need to have one
more block for negaive signe in memory

n: the integer to convert.

Return value:
    The string representing the integer. NULL if the allocation fails.

#61 i need to fill the str from the end thats why i need to put the index as 
str_size - 1 but i use prefix decriment for use less code insted of(str_size-1
and after that str_size--)
*/

size_t	digit_num(int n)
{
	size_t	digit_num;

	digit_num = 0;
	while (n)
	{
		n /= 10;
		digit_num++;
	}
	return (digit_num);
}

char	*ft_itoa(int n)
{
	long int	num;
	size_t		str_size;
	char		*str;

	num = n;
	str_size = digit_num(n);
	if (n <= 0)
	{
		num *= -1;
		str_size++;
	}
	str = (char *)ft_calloc((str_size + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (str_size)
	{
		str[--str_size] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		str[str_size] = '-';
	return (str);
}
