/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:06:58 by rmohamma          #+#    #+#             */
/*   Updated: 2023/03/13 15:07:01 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_error(char *error)
{
	write(STDERR_FILENO, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

void	ft_perror(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

void	cmd_error(char *cmd)
{
	if (cmd && *cmd != '\0')
	{	
		write(STDERR_FILENO, cmd, ft_strlen(cmd));
		write(STDERR_FILENO, ERR_CMD, ft_strlen(ERR_CMD));
		write(STDERR_FILENO, "\n", ft_strlen("\n"));
	}
}
