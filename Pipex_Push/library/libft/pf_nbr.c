/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:27:25 by rmohamma          #+#    #+#             */
/*   Updated: 2023/01/02 13:27:28 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*long and long int are identical. So are long long and long long int. In both 
cases, the int is optional.

#25 for int_min i have timeout if i convert int to a long
*/
int	pf_int(int num)
{
	int	ret;

	ret = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (num < 0)
	{
		ret += pf_char('-');
		ret += pf_int(num * -1);
	}
	else if (num > 9)
	{
		ret += pf_int(num / 10);
		ret += pf_char((num % 10) + '0');
	}
	else
		ret += pf_char(num + '0');
	return (ret);
}

int	pf_unint(unsigned int num)
{
	int	ret;

	ret = 0;
	if (num <= 9)
	{
		ret += pf_char(num + '0');
		return (ret);
	}
	else if (num > 9)
	{
		ret += pf_unint(num / 10);
		ret += pf_char(num % 10 + '0');
		return (ret);
	}
	else
		return (0);
}
