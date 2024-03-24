/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:24:51 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/07 21:24:51 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	print_error_utils(int exit);

static void	free_split(char **split);

void	wait_all_pid(t_pipex *pipex)
{
	int	i;
	int	status;

	i = -1;
	while (++i <= pipex->indice_pid)
	{
		status = 0;
		if (pipex->pid[i] == -1)
			break ;
		waitpid(pipex->pid[i], &status, 2);
		print_error(status >> 8, pipex, i);
	}
	free(pipex->pid);
}

void	print_error(int exit, t_pipex *pipex, int i_pid)
{
	if (exit == EXIT_FILE_NOT_EXIST || exit == EXIT_CMD_NOT_DIRECTORY)
	{
		ft_putstr_fd(ERROR_2, STDERR_FILENO);
		ft_putstr_fd(pipex->argv[(exit == EXIT_CMD_NOT_DIRECTORY) * \
		(i_pid + 1) + 1 + (pipex->here_doc == TRUE)], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	else if (exit == EXIT_CMD_NOT_FOUND)
	{
		ft_putstr_fd(ERROR_CMD_NOT_FOUND, STDERR_FILENO);
		ft_putstr_fd(pipex->argv[i_pid + 2 + (pipex->here_doc == TRUE)], \
		STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	else if (exit == EXIT_ENV)
	{
		ft_putstr_fd(ENV_ERROR_1, STDERR_FILENO);
		ft_putstr_fd(pipex->argv[i_pid + 2 + (pipex->here_doc == TRUE)], \
		STDERR_FILENO);
		ft_putstr_fd(ENV_ERROR_2, STDERR_FILENO);
	}
	print_error_utils(exit);
}

static void	print_error_utils(int exit)
{
	if (exit == EXIT_DUP2FAIL)
		ft_putstr_fd(ERROR_DUP, STDERR_FILENO);
	else if (exit == EXIT_MALLOC)
		ft_putstr_fd(ERROR_MALLOC, STDERR_FILENO);
	else if (exit == EXIT_EXECVE_FAIL)
		ft_putstr_fd(ERROR_EXECVE, STDERR_FILENO);
	else if (exit == EXIT_FORK_FAIL)
		ft_putstr_fd(ERROR_FORK, STDERR_FILENO);
	else if (exit == EXIT_OPEN_FAIL)
		ft_putstr_fd(ERROR_OPEN, STDERR_FILENO);
	else if (exit == EXIT_PIPE_FAIL)
		ft_putstr_fd(ERROR_PIPE, STDERR_FILENO);
	else if (exit == EXIT_EMPTY_CMD)
		ft_putstr_fd(ERROR_EMPTY_CMD, STDERR_FILENO);
	else if (exit == EXIT_UNLINK)
		ft_putstr_fd(ERROR_UNLINK, STDERR_FILENO);
	else if (exit == EXIT_READ_FAIL)
		ft_putstr_fd(ERROR_READ_FAIL, STDERR_FILENO);
}

void	error_execve(t_exec_info *exec_info, t_exit_value exit_value)
{
	close(0);
	close(1);
	if (exec_info->arg)
		free_split(exec_info->arg);
	if (exec_info->elmnt_path)
		free_split(exec_info->elmnt_path);
	if (exec_info->path_test)
		free(exec_info->path_test);
	exit(exit_value);
}

static void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
