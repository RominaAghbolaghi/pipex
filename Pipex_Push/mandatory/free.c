/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:07:23 by rmohamma          #+#    #+#             */
/*   Updated: 2023/03/13 15:07:25 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_malloc(char **ptr_ptr)
{
	int	i;

	i = 0;
	while (ptr_ptr[i])
	{
		free(ptr_ptr[i]);
		i++;
	}
	free(ptr_ptr);
}

void	parent_free(t_mpipex *pipex)
{
	free_malloc(pipex->cmd_addr);
	free(pipex->pipe_fd);
}

void	child_free(t_mpipex *pipex)
{
	if (pipex->infile)
		close(pipex->infile);
	if (pipex->outfile)
		close(pipex->outfile);
	free_malloc(pipex->cmd_addr);
	free_malloc(pipex->cmd_argv);
	free(pipex->pipe_fd);
}

void	cmd_free(t_mpipex *pipex)
{
	free(pipex->pipe_fd);
	free(pipex->path_value);
	free_malloc(pipex->cmd_addr);
	ft_error(ERR_ENV);
}
