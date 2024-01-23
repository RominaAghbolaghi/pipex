/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:06:38 by rmohamma          #+#    #+#             */
/*   Updated: 2023/03/13 15:06:40 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*access_cmd(char **cmd_addr, char *cmd)
{
	char	*temp;
	char	*command;

	if (cmd)
	{
		while (*cmd_addr)
		{
			temp = ft_strjoin(*cmd_addr, "/");
			command = ft_strjoin(temp, cmd);
			free(temp);
			if (access(command, F_OK) == 0)
				return (command);
			free(command);
			cmd_addr++;
		}
	}
	return (NULL);
}

static void	duplicate(int dup_stdin, int dup_stdout)
{
	dup2(dup_stdin, STDIN_FILENO);
	dup2(dup_stdout, STDOUT_FILENO);
}

static void	ft_command(t_mpipex *pipex, char **argv, char **envp)
{
	pipex->cmd_argv = ft_split(argv[2 + pipex->pipe_index],
			' ');
	if (!*pipex->cmd_argv)
	{
		child_free(pipex);
		ft_error(ERR_EMPTY);
	}
	pipex->cmd = access_cmd(pipex->cmd_addr, pipex->cmd_argv[0]);
	if (!pipex->cmd)
	{
		cmd_error(pipex->cmd_argv[0]);
		child_free(pipex);
		free(pipex->cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(pipex->cmd, pipex->cmd_argv, envp) < 0)
	{
		child_free(pipex);
		free(pipex->cmd);
		ft_error(ERR_ACCESS);
		exit(EXIT_FAILURE);
	}
}

void	ft_fork(t_mpipex pipex, char **argv, char **envp)
{
	int	index;

	index = pipex.pipe_index;
	pipex.pid = fork();
	if (!pipex.pid)
	{
		if (index == 0)
			duplicate(pipex.infile, pipex.pipe_fd[1]);
		else if (index == pipex.cmd_num - 1)
			duplicate(pipex.pipe_fd[2 * index - 2], pipex.outfile);
		else
			duplicate(pipex.pipe_fd[2 * index - 2],
				pipex.pipe_fd[2 * index + 1]);
		close_fds(&pipex);
		ft_command(&pipex, argv, envp);
	}
}
