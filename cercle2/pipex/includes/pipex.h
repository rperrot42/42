/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:14:47 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/23 18:32:56 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

# define ERROR_2 "pipex: no such file or directory: "
# define ERROR_DUP "pipex: dup2 fail\n"
# define ERROR_FORK "pipex: fork fail\n"
# define ERROR_CMD_NOT_FOUND "pipex: command not found: "
# define PATH_DEFAULT "PATH=/home/rperrot/bin:/usr/local/sbin:/usr/local/bin:/usr/s\
bin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"
# define ENV_ERROR_1 "env: '"
# define ENV_ERROR_2 "’: No such file or directory\n"
# define ERROR_MALLOC "pipex: fail malloc\n"
# define ERROR_EXECVE "pipex: execve fail\n"
# define ERROR_FORK "pipex: fork fail\n"
# define ERROR_PIPE "pipex: pipe fail\n"
# define ERROR_OPEN "pipex: open fail\n"
# define ERROR_EMPTY_CMD "pipex: permission denied:\n"
# define ERROR_ARGS "pipex: Insufficient arguments provided. Please provide \
the required arguments.\n"
# define ERROR_UNLINK "pipex: unlink fail\n"
# define FILE_RANDOM "/dev/urandom"
# define HERE_DOC "here_doc"
# define ERROR_READ_FAIL "pipex: read fail\n"

typedef enum e_exit_value
{
	EXIT_SUCCE,
	EXIT_DUP2FAIL,
	EXIT_FILE_NOT_EXIST,
	EXIT_CMD_NOT_FOUND,
	EXIT_ENV,
	EXIT_MALLOC,
	EXIT_EXECVE_FAIL,
	EXIT_PIPE_FAIL,
	EXIT_FORK_FAIL,
	EXIT_OPEN_FAIL,
	EXIT_EMPTY_CMD,
	EXIT_UNLINK,
	EXIT_READ_FAIL,
	EXIT_CMD_NOT_DIRECTORY
}	t_exit_value;

typedef struct s_pipex
{
	int		fd[2];
	pid_t	*pid;
	char	**argv;
	char	**env;
	int		argc;
	t_bool	here_doc;
	int		indice_pid;
}	t_pipex;

typedef struct s_exec_info
{
	char	**elmnt_path;
	char	*path_test;
	char	**arg;
	int		result_search_path_env;
}	t_exec_info;

int		exec_cmd(char *cmd, char **env);
int		ft_pipex(t_pipex *pipex);
void	wait_all_pid(t_pipex *pipex);
void	print_error(int exit, t_pipex *pipex, int i_pid);
void	read_here_doc(char *limiter, int *fd_file_enter, int fd1);
void	error_execve(t_exec_info *exec_info, t_exit_value exit_value);
void	init_exec_info(t_exec_info *exec_info);
#endif
