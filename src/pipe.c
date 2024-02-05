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

int	read_here_doc(char *limiter, int *fd_file_enter)
{
	char	*line;

	*fd_file_enter = open("a",  O_WRONLY | O_CREAT | O_TRUNC, "0777");
	line = get_next_line(0);
	while (ft_strncmp(line, limiter,ft_findnewline(line) - 1))
	{

		if (ft_strncmp(line, limiter,ft_findnewline(line) - 1))
			write(*fd_file_enter, line, ft_findnewline(line));

		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(*fd_file_enter);
	*fd_file_enter = open("a",  O_RDONLY);
	return (0);
}

int first_execve(char **argv, char **env, int fd[2], t_bool here_doc)
{
	int	fd_file_enter;
	if (here_doc == FALSE)
		fd_file_enter = open(argv[1], O_RDONLY);
	else
		read_here_doc(argv[2], &fd_file_enter);
	close(fd[0]);
	dup2(fd_file_enter, 0);
	dup2(fd[1], 1);
	close(fd_file_enter);
	close(fd[1]);
	char buffer[100];
	read(fd_file_enter, buffer, 10);
	if (here_doc == FALSE)
		return (exec_cmd(argv[2], env));
	else
	{
		unlink("a");
		return (exec_cmd(argv[3], env));
	}
}

int last_execve(char **argv, char **env, int fd[2], int argc)
{
	int	fd_file_exit;
	fd_file_exit = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
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
	if (!ft_strncmp("here_doc", argv[1], 9))
		i = 3;
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
			return (exec_cmd(argv[i], env));
		}
		close(fd[1]);
		close(fd_in);
	}
	return (fd[0]);
}

int	pipep(int argc, char **argv, char **env, t_bool here_doc)
{
	pid_t	pid;
	int		fd[2];
    int		stdouut;

	here_doc = FALSE;
	if (!ft_strncmp("here_doc", argv[1], 9))
		here_doc = TRUE;
	pipe(fd);
	pid = fork();
    stdouut = dup(1);
	if (pid == 0) {
		close(stdouut);
		first_execve(argv, env, fd, here_doc);
	}
	close(fd[1]);
	if ((argc > 5 && here_doc == FALSE) || (argc > 6 && here_doc == TRUE))
		fd[0] = mid_execve(argv, env, fd, argc);
	last_execve(argv, env, fd, argc);
	return (0);
}