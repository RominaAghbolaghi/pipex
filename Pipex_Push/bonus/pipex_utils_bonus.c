/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:17:51 by rmohamma          #+#    #+#             */
/*   Updated: 2023/03/13 15:18:10 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	here_doc_check(char *second_argv, t_mpipex *pipex)
{
	if (second_argv && !ft_strncmp("here_doc", second_argv, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

void	open_infile(char **argv, t_mpipex *pipex)
{
	if (pipex->here_doc == 1)
		here_doc_infile(argv[2], pipex);
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
		{
			parent_free(pipex);
			ft_perror(ERR_INFILE);
		}
	}
}

static void	writein_heredoc_infile(char *delimiter, int fd, t_mpipex *pipex)
{
	char	*line;

	line = NULL;
	while (1)
	{
		write(STDIN_FILENO, "> ", ft_strlen("> "));
		line = get_next_line(0);
		if (!line)
		{
			close(fd);
			free(line);
			parent_free(pipex);
			ft_error(ERR_INPUT);
		}
		if (!ft_strncmp(delimiter, line, ft_strlen(line) - 1))
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(fd);
}

void	here_doc_infile(char *delimiter, t_mpipex *pipex)
{
	int		fd;

	fd = open("heredoc_infile", O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR);
	if (fd < 0)
	{
		parent_free(pipex);
		ft_perror(ERR_HEREDOC);
	}
	writein_heredoc_infile(delimiter, fd, pipex);
	pipex->infile = open("heredoc_infile", O_RDONLY);
	if (pipex->infile < 0)
	{
		if (pipex->here_doc)
			unlink("heredoc_infile");
		parent_free(pipex);
		ft_perror(ERR_HEREDOC);
	}
}

void	open_outfile(char *last_argv, t_mpipex *pipex)
{
	if (pipex->here_doc)
		pipex->outfile = open(last_argv, O_CREAT | O_RDWR | O_APPEND,
				S_IRUSR | S_IWUSR);
	else
		pipex->outfile = open(last_argv, O_CREAT | O_RDWR | O_TRUNC,
				S_IRUSR | S_IWUSR);
	if (pipex->outfile < 0)
	{
		parent_free(pipex);
		ft_perror(ERR_OUTFILE);
	}
}
