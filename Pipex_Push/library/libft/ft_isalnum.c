/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:34:18 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/14 13:48:49 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
ctype.h header file

checks whether the argument passed is an alphanumeric character (alphabet or 
number) or not.

it is equivalent to (ft_isalpha or ft_isdigit)

!!!!!Even though, isalnum() takes integer as an argument, character is passed 
to the function!
*/

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
