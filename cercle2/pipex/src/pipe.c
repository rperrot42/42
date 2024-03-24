/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:26:49 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/22 21:58:33 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_execve(t_pipex *pipex)
{
	int	fd_file_enter;

	free(pipex->pid);
	close(pipex->fd[0]);
	if (pipex->here_doc == FALSE)
		fd_file_enter = open(pipex->argv[1], O_RDONLY);
	else
		read_here_doc(pipex->argv[2], &fd_file_enter, pipex->fd[1]);
	if (fd_file_enter == -1)
		return (close(pipex->fd[1]), exit(EXIT_FILE_NOT_EXIST));
	if (dup2(pipex->fd[0], 0) == -1)
		return (close(fd_file_enter), close(pipex->fd[1]), exit(EXIT_DUP2FAIL));
	if (dup2(pipex->fd[1], 1) == -1)
		return (close(fd_file_enter), close(0), close(pipex->fd[1]), \
		exit(EXIT_DUP2FAIL));
	close(fd_file_enter);
	close(pipex->fd[1]);
	if (pipex->here_doc == FALSE)
		exec_cmd(pipex->argv[2], pipex->env);
	else
		exec_cmd(pipex->argv[3], pipex->env);
}

void	last_execve(t_pipex *pipex)
{
	int	fd_file_exit;

	free(pipex->pid);
	if (pipex->here_doc == FALSE)
		fd_file_exit = open(pipex->argv[pipex->argc - 1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd_file_exit = open(pipex->argv[pipex->argc - 1], \
		O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_file_exit == -1)
		return (close(pipex->fd[0]), exit(EXIT_OPEN_FAIL));
	if (dup2(pipex->fd[0], 0) == -1)
		return (close(pipex->fd[0]), close(fd_file_exit), exit(EXIT_DUP2FAIL));
	if (dup2(fd_file_exit, 1) == -1)
		return (close(pipex->fd[0]), close(fd_file_exit), \
		close(0), exit(EXIT_DUP2FAIL));
	close(pipex->fd[0]);
	close(fd_file_exit);
	exec_cmd(pipex->argv[pipex->argc - 2], pipex->env);
}

void	child_mid_execve(t_pipex *pipex, int fd_in, int indice_argv)
{
	free(pipex->pid);
	close(pipex->fd[0]);
	if (dup2(fd_in, 0) == -1)
		return (close(fd_in), close(pipex->fd[1]), exit(EXIT_DUP2FAIL));
	if (dup2(pipex->fd[1], 1) == -1)
		return (close(fd_in), close(pipex->fd[1]), close(0), \
exit(EXIT_DUP2FAIL));
	close(pipex->fd[1]);
	close(fd_in);
	exec_cmd(pipex->argv[indice_argv], pipex->env);
}

int	mid_execve(t_pipex *pipex)
{
	int	i;
	int	fd_in;

	i = 2;
	if (!ft_strncmp("here_doc", pipex->argv[1], 9))
		i = 3;
	while (++i < pipex->argc - 2)
	{
		fd_in = pipex->fd[0];
		if (pipe(pipex->fd) == -1)
			return (close(fd_in), -EXIT_PIPE_FAIL);
		pipex->pid[++pipex->indice_pid] = fork();
		if (pipex->pid[pipex->indice_pid] == -1)
			return (close(fd_in), close(pipex->fd[0]), \
			close(pipex->fd[1]), -EXIT_FORK_FAIL);
		if (pipex->pid[pipex->indice_pid] == 0)
			child_mid_execve(pipex, fd_in, i);
		close(pipex->fd[1]);
		close(fd_in);
	}
	return (pipex->fd[0]);
}

int	ft_pipex(t_pipex *pipex)
{
	pipex->pid = malloc(sizeof(pid_t) * \
	(pipex->argc - 3 - (pipex->here_doc == TRUE)));
	if (!pipex->pid)
		return (EXIT_MALLOC);
	if (pipe(pipex->fd) == -1)
		return (EXIT_PIPE_FAIL);
	pipex->pid[++pipex->indice_pid] = fork();
	if (pipex->pid[pipex->indice_pid] == -1)
		return (close(pipex->fd[0]), close(pipex->fd[1]), EXIT_FORK_FAIL);
	if (pipex->pid[pipex->indice_pid] == 0)
		first_execve(pipex);
	close(pipex->fd[1]);
	if ((pipex->argc > 5 && pipex->here_doc == FALSE) || \
	(pipex->argc > 6 && pipex->here_doc == TRUE))
		pipex->fd[0] = mid_execve(pipex);
	if (pipex->fd[0] < 0)
		return (-pipex->fd[0]);
	pipex->pid[++pipex->indice_pid] = fork();
	if (pipex->pid[pipex->indice_pid] == 0)
		last_execve(pipex);
	close(pipex->fd[0]);
	if (pipex->pid[pipex->indice_pid] == -1)
		return (EXIT_FORK_FAIL);
	return (EXIT_SUCCESS);
}
