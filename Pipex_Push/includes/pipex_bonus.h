/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:09:45 by rmohamma          #+#    #+#             */
/*   Updated: 2023/03/13 15:09:47 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/*to perror*/
# include <stdio.h>
# include <errno.h>
/* to get libft*/
# include "../library/libft/libft.h"
/* to get_next_line */
# include "../library/GNL/get_next_line.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_HEREDOC "here_doc didn't open"
# define ERR_PIPE "Pipe error"
# define ERR_ARGV "Invalid number of arguments.\n"
# define ERR_INPUT "\nwarning: here-document delimited by end-of-file\n"
# define ERR_ENV "Environment\n"
# define ERR_MEMO "memory not allocated\n"
# define ERR_CMD ": command not found"
# define ERR_ACCESS "execve() error\n"
# define ERR_EMPTY "empty command\n"

typedef struct s_mpipex
{
	pid_t	pid;
	int		here_doc;
	int		infile;
	int		outfile;
	int		cmd_num;
	int		fd_num;
	int		*pipe_fd;
	int		pipe_index;
	char	*path_value;
	char	**cmd_addr;
	char	**cmd_argv;
	char	*cmd;
}	t_mpipex;

/* pipex_bonus.c */
void	open_infile(char **argv, t_mpipex *pipex);
void	open_outfile(char *last_argv, t_mpipex *pipex);
void	close_fds(t_mpipex *pipex);
char	*path_value(char **envp);

/* pipex_utils_bonus.c */
int		here_doc_check(char *second_argv, t_mpipex *pipex);
void	here_doc_infile(char *delimiter, t_mpipex *pipex);

/* fork_bonus.c */
void	ft_fork(t_mpipex pipex, char **argv, char **envp);

/* free.c */
void	parent_free(t_mpipex *pipex);
void	child_free(t_mpipex *pipex);
void	cmd_free(t_mpipex *pipex);

/* error_bonus.c */
void	ft_perror(char *error);
void	cmd_error(char *cmd);
void	ft_error(char *error);

void	free_malloc(char **ptr_ptr);

#endif
