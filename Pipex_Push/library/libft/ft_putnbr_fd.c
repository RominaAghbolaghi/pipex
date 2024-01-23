/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:26:47 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/28 15:26:51 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Outputs the integer ’n’ to the given file descriptor.

Parameters:
	n: The integer to output.
	fd: The file descriptor on which to write.

#35 recursive call of the function
External functs: write
		#include <unistd.h>
		ssize_t write(int fildes, const void *buf, size_t nbyte);
*/
void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((nbr % 10 + '0'), fd);
}
