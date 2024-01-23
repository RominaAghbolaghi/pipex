/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:32:12 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/28 14:32:17 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Outputs the character ’c’ to the given file descriptor(fd).

Parameters:
	c: The character to output.
	fd: The file descriptor on which to write.

External functs: write
		#include <unistd.h>
		ssize_t write(int fildes, const void *buf, size_t nbyte);

The write() function shall attempt to write nbyte bytes from the buffer 
POINTED TO BY BUF to the file associated with the open file descriptor, fildes.

a file descriptor (FD, less frequently fildes) is a process-unique identifier 
(handle) for a file or other input/output resource
*/

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
