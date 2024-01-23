/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:38:48 by rmohamma          #+#    #+#             */
/*   Updated: 2022/12/12 14:40:20 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
the C programming langage gives you printf() that lets you write data in many 
different formats. So, you can understand printf() as a function that convert 
your data into a formatted sequence of bytes and that calls write() to write 
those bytes onto the output.

The C library function int printf(const char *format, ...) sends formatted 
output to stdout(standard output from from file descriptor)

format − This is THE STRING that contains THE TEXT to be written to STDOUT. 
It can optionally contain embedded (jasazi) format tags that are replaced by 
the values specified in subsequent additional arguments and formatted as 
requested.

Return Value:
If successful, THE TOTAL NUMBER OF CHARACTERS WRITTEN is returned. On failure, 
a NEGATIVE NUMBER is returned.

unsigned long long int:It is the largest (64 bit) integer data type


For a variadic function, the compiler doesn't know the types of the parameters
corresponding to the , .... For historical reasons, and to make the compiler's 
job easier, any corresponding arguments of types narrower than int are promoted 
to int or to unsigned int, and any arguments of type float are promoted to 
double.

a variadic function can't receive arguments of type char. You can call such a 
function with a char argument, but it will be promoted to int.

%c - convert an int to an unsigned character and print the resulting character
%s - print the string pointed to by a char *
%d - specifies signed decimal integer while %i specifies integer.
they print an int as a signed decimal number
%u - unsigned int, print an unsigned as an unsigned decimal number
%x or X - print an unsigned as an unsigned hexadecimal number (where the letters 
abcdef are used with x and ABCDEF are used with X)
For x or X, a non-zero value has a 0x prepended (or 0X for the X specification)
to save a hexa in a long data type we need to add L at the end
%p - print a void * argument in hexadecimal (ANSI C only)
In 16-bit systems, the size of a void pointer is 2 bytes. In a 32-bit system, 
the size of a void pointer is 4 bytes. And, in a 64-bit system, the size of a 
void pointer is 8 bytes. so long is enough
Symbol 0x (computing) Indicates that the number that follows is in hexadecimal.
*/

int	print_varg(va_list ap, char c);

//it is a variadic function
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	if (!format)
		return (0);
	va_start(ap, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			ret += print_varg(ap, format[i]);
		}
		else
			ret += pf_char(format[i]);
	}
	va_end(ap);
	return (ret);
}
// we dont need to convert to char

int	print_varg(va_list ap, char c)
{
	unsigned long	addr;

	if (c == 'c')
		return (pf_char((char)va_arg(ap, int)));
	else if (c == 's')
		return (pf_str(va_arg(ap, char *)));
	else if (c == 'i' || c == 'd')
		return (pf_int(va_arg(ap, int)));
	else if (c == 'u')
		return (pf_unint(va_arg(ap, int)));
	else if (c == 'x' || c == 'X')
		return (pf_base(va_arg(ap, int), c));
	else if (c == 'p')
	{
		addr = va_arg(ap, unsigned long);
		if (addr == 0)
			return (pf_str("(nil)"));
		else
			return (pf_str("0x") + pf_pointer(addr));
	}
	else if (c == '%')
		return (pf_char('%'));
	return (0);
}
