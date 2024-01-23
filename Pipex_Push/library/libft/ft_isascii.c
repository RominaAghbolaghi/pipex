/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:56:50 by rmohamma          #+#    #+#             */
/*   Updated: 2022/11/14 14:00:31 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The difference between int and const int is that int is read/write while const 
int is read-only
*/
int	ft_isascii(const int c)
{
	return (c >= 0 && c <= 127);
}
