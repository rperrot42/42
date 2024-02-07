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

void	replace_slash(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			str[i] = 'A';
		i++;
	}
}

int	create_name(char **name)
{
	int	fd_rand;

	fd_rand = open("/dev/urandom", O_RDONLY);
	if (fd_rand == -1)
		return (-1);
	*name = malloc(sizeof(char) * 25);
	if (!(*name))
		return (close(fd_rand), -2);
	if (read(fd_rand, *name, 24) == -1)
	{
		free(*name);
		close(fd_rand);
		return (-3);
	}
	close(fd_rand);
	(*name)[24] = 0;
	replace_slash(*name);
	return (0);
}

int	read_here_doc(char *limiter, int *fd_file_enter, char *name)
{
	char	*line;

	*fd_file_enter = open(name,  O_WRONLY | O_CREAT, 0777);

	line = get_next_line(0);
	while (ft_findnewline(line) <= 1 || ft_strncmp(line, limiter,ft_findnewline(line) - 1))
	{

		if (ft_strncmp(line, limiter,ft_findnewline(line) - 1))
			write(*fd_file_enter, line, ft_findnewline(line));
		free(line);
		line = get_next_line(0);
	}
	close(*fd_file_enter);
	*fd_file_enter = open(name,  O_RDONLY | O_CREAT, 0777);
	unlink(name);
	free(line);
	return (0);
}

int first_execve(char **argv, char **env, int fd[2], t_bool here_doc, char *name)
{
	int	fd_file_enter;

	if (here_doc == FALSE)
		fd_file_enter = open(argv[1], O_RDONLY);
	else
		read_here_doc(argv[2], &fd_file_enter, name);
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
		return (exec_cmd(argv[3], env));
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
		wait(NULL);
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
	char	*name;

	if (here_doc == TRUE)
		if (create_name(&name) < 0)
			return (-1);
	if (pipe(fd) == -1)
		return (free(name), -1);
	if (pid = fork() == -1);
		return (free(name), -1);
	if (pid == 0)
		first_execve(argv, env, fd, here_doc, name);
	close(fd[1]);
	if ((argc > 5 && here_doc == FALSE) || (argc > 6 && here_doc == TRUE))
		fd[0] = mid_execve(argv, env, fd, argc);
	wait(NULL);
	ft_printf("%d\n", last_execve(argv, env, fd, argc));
	return (0);
}