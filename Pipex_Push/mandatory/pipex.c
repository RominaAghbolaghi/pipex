/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:05:51 by rmohamma          #+#    #+#             */
/*   Updated: 2023/03/13 15:05:54 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	creat_pipes(t_mpipex *pipex)
{
	int	pipe_ind;

	pipe_ind = 0;
	while (pipe_ind < pipex->cmd_num - 1)
	{
		if (pipe(pipex->pipe_fd + (2 * pipe_ind)) < 0)
		{
			parent_free(pipex);
			ft_perror(ERR_PIPE);
		}
		pipe_ind++;
	}
}

char	*path_value(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	close_fds(t_mpipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->fd_num)
	{
		close(pipex->pipe_fd[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mpipex	pipex;

	if (argc != 5)
		ft_error(ERR_ARGV);
	pipex.cmd_num = argc - 3;
	pipex.fd_num = 2 * (pipex.cmd_num - 1);
	pipex.pipe_fd = (int *)malloc(sizeof(int) * (pipex.fd_num));
	if (!pipex.pipe_fd)
		ft_error(ERR_MEMO);
	pipex.path_value = path_value(envp);
	pipex.cmd_addr = ft_split(pipex.path_value, ':');
	if (!pipex.cmd_addr)
		cmd_free(&pipex);
	open_infile(argv, &pipex);
	open_outfile(argv[argc - 1], &pipex);
	creat_pipes(&pipex);
	pipex.pipe_index = -1;
	while (++(pipex.pipe_index) < pipex.cmd_num)
		ft_fork(pipex, argv, envp);
	close_fds(&pipex);
	waitpid(-1, NULL, 0);
	parent_free(&pipex);
	return (0);
}
