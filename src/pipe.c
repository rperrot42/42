/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:26:49 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/31 16:26:49 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/pipex.h"
#include <stdio.h>

int first_execve(char **argv, char **env, int fd[2])
{
	int	fd_file_enter;

	fd_file_enter = open(argv[1], O_RDONLY);
	close(fd[0]);
	dup2(fd_file_enter, 0);
	dup2(fd[1], 1);
	close(fd_file_enter);
	close(fd[1]);
	return (exec_cmd(argv[2], env));

}

int last_execve(char **argv, char **env, int fd[2], int argc)
{
	int	fd_file_exit;

	fd_file_exit = open(argv[argc - 1], O_WRONLY);
	dup2(fd[0], 0);
	dup2(fd_file_exit, 1);
	close(fd[0]);
	close(fd_file_exit);
	return (exec_cmd(argv[argc - 2], env));
}

int mid_execve(char **argv, char **env, int fd[2], int argc)
{
	int i;
	int fd_in;
	int	pid;

	i = 2;
	while (++i < argc - 2)
	{
		fd_in = fd[0];
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			close(fd[0]);
			dup2(fd_in, 0);
			dup2(fd[1], 1);
			close(fd[1]);
			close(fd_in);
			return (execv(argv[i], env));
		}
		close(fd[1]);
		close(fd_in);
	}
	return (fd[0]);
}

int	pipep(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];
    int stdouut;

    ft_printf("%d\n", getpid());
	pipe(fd);
	pid = fork();
    stdouut = dup(1);
	if (pid == 0) {
		close(stdouut);
		first_execve(argv, env, fd);
	}
	close(fd[1]);
	if (argc > 4)
		fd[0] = mid_execve(argv, env, fd, argc);
	last_execve(argv, env, fd, argc);
	return (0);
}