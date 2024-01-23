/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:23:14 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/28 15:23:18 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Outputs 
  the string ’s’ to the given file descriptor(putstr) followed by 
a newline(putchr)
the newline CHARACTER is represented as a '\n' which is an escape sequence.

Parameters:
s: The string to output.
fd: The file descriptor on which to write.

External functs: write
*/
void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}
