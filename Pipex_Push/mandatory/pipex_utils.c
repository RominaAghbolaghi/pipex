/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:17:51 by rmohamma          #+#    #+#             */
/*   Updated: 2023/03/13 15:18:10 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	open_infile(char **argv, t_mpipex *pipex)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		parent_free(pipex);
		ft_perror(ERR_INFILE);
	}
}

void	open_outfile(char *last_argv, t_mpipex *pipex)
{
	pipex->outfile = open(last_argv, O_CREAT | O_RDWR | O_TRUNC,
			S_IRUSR | S_IWUSR);
	if (pipex->outfile < 0)
	{
		parent_free(pipex);
		ft_perror(ERR_OUTFILE);
	}
}
