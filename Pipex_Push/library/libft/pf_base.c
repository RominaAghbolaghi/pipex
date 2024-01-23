/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:27:54 by rmohamma          #+#    #+#             */
/*   Updated: 2023/01/02 13:27:57 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
pointer does not accept the unsiged int
hexa dose not work with unsigned long for negative numbers
we need to add L at the end of it to save hexa in long data type
*/

int	putbase_hex(unsigned long num, char *base);

int	pf_base(unsigned int arg, char c)
{
	int				ret;
	char			*base;

	ret = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ret += putbase_hex(arg, base);
	return (ret);
}

int	putbase_hex(unsigned long num, char *base)
{
	int	ret;

	ret = 0;
	if (num >= 16)
		ret += putbase_hex((num / 16), base);
	ret += pf_char(base[num % 16]);
	return (ret);
}

int	pf_pointer(unsigned long addr)
{
	int		ret;
	char	*base;

	ret = 0;
	base = "0123456789abcdef";
	ret += putbase_hex(addr, base);
	return (ret);
}
