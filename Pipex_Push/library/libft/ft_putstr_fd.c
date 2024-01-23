/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:17:38 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/28 15:17:42 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Outputs the string ’s’ to the given file descriptor.

Parameters:
s: The string to output.
fd: The file descriptor on which to write.

External functs: write
		#include <unistd.h>
		ssize_t write(int fildes, const void *buf, size_t nbyte);
*/
void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			write (fd, &s[i], 1);
			i++;
		}
	}
}
