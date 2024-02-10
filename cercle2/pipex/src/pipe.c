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

void	create_name(char **name)
{
	int	fd_rand;

	fd_rand = open("/dev/urandom", O_RDONLY);
	if (fd_rand == -1)
		exit(1);
	*name = malloc(sizeof(char) * 25);
	if (!(*name))
		return (error_close(fd_rand), exit(1));
	if (read(fd_rand, *name, 24) == -1)
	{
		free(*name);
		error_close(fd_rand);
		exit(1);
	}
	if (error_close(fd_rand) == -1)
		return (free(name), exit(1));
	(*name)[24] = 0;
	replace_slash(*name);
}

void	read_here_doc(char *limiter, int *fd_file_enter)
{
	char	*line;
	char	*name;


	create_name(&name);
	name[0] = 'd';
	name[1] = 0;
	*fd_file_enter =  open(name,  O_WRONLY | O_CREAT, 0777);
	if (*fd_file_enter == -1)
		return (free(name), exit(1));
	line = get_next_line(0);
	while (ft_findnewline(line) <= 1 || ft_strncmp(line, limiter,ft_findnewline(line) - 1))
	{

		if (ft_strncmp(line, limiter,ft_findnewline(line) - 1))
			write(*fd_file_enter, line, ft_findnewline(line));
		free(line);
		line = get_next_line(0);
		if (!line)
			return (error_close(*fd_file_enter), free(name), exit(1));
	}
	free(line);
	if (error_close(*fd_file_enter) == -1)
		return (free(name), exit(1));
	*fd_file_enter = open(name,  O_RDONLY | O_CREAT);
	free(name);
	if (*fd_file_enter == -1)
		return (exit(1));
	unlink(name);
}

void first_execve(char **argv, char **env, int fd[2], t_bool here_doc)
{
	int	fd_file_enter;

	if (here_doc == FALSE)
		fd_file_enter = open(argv[1], O_RDONLY);
	else
		read_here_doc(argv[2], &fd_file_enter);
	if (fd_file_enter == -1)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd("\n", 2);
	}
	if (error_close(fd[0]))
		return (error_close(fd_file_enter), error_close(fd[1]), exit(1));
	if (dup2(fd_file_enter, 0) == -1)
		return (error_close(fd_file_enter), error_close(fd[1]), exit(1));
	if (dup2(fd[1], 1) == -1)
		return (error_close(fd_file_enter), error_close(0), error_close(fd[1]),  exit(1));
	if (error_close(fd_file_enter) == -1)
		return (error_close(0), error_close(1), error_close(fd[1]),  exit(1));
	if (error_close(fd[1]) == -1)
		return (error_close(0), error_close(1),  exit(1));
	if (here_doc == FALSE)
		exec_cmd(argv[2], env);
	else
		exec_cmd(argv[3], env);
}

void last_execve(char **argv, char **env, int fd[2], int argc)
{
	int	fd_file_exit;

	fd_file_exit = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd_file_exit == -1)
		return (error_close(fd[0]), exit(1));
	if (dup2(fd[0], 0) == -1)
		return (error_close(fd[0]), error_close(fd_file_exit), exit(1));
	if (dup2(fd_file_exit, 1) == -1)
		return (error_close(fd[0]), error_close(fd_file_exit), error_close(0), exit(1));
	if (error_close(fd[0]) == -1)
		return (error_close(1), error_close(fd_file_exit), error_close(0), exit(1));
	if (error_close(fd_file_exit))
		return (error_close(1), error_close(0), exit(1));
	exec_cmd(argv[argc - 2], env);
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
		if (pipe(fd) == -1)
			return (error_close(fd_in), exit(1), -1);
		pid = fork();
		if (pid == -1)
			return (error_close(fd_in), error_close(fd[0]), error_close(fd[1]), exit(1), -1);
		if (pid == 0)
		{
			if (error_close(fd[0]) == -1)
				return (error_close(fd_in), error_close(fd[1]), exit(1), -1);
			if (dup2(fd_in, 0) == -1)
				return (error_close(fd_in), error_close(fd[1]), exit(1), -1);
			if (dup2(fd[1], 1) == -1)
				return (error_close(fd_in), error_close(fd[1]), error_close(0), exit(1), -1);
			if (error_close(fd[1]) == -1)
				return (error_close(fd_in), error_close(1), error_close(0), exit(1), -1);
			if (error_close(fd_in) == -1)
				return (error_close(1), error_close(0), exit(1), -1);
			exec_cmd(argv[i], env);
		}
		if (error_close(fd[1]) == -1)
			return (error_close(fd[0]), error_close(fd_in), exit(1), -1);
		if (error_close(fd_in) == -1)
			return (error_close(fd[0]), exit(1), -1);
	}
	return (fd[0]);
}

int	pipep(int argc, char **argv, char **env, t_bool here_doc)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return  (-1);
	if (pid == 0)
		first_execve(argv, env, fd, here_doc);
	if (error_close(fd[1]) == -1)
		return (error_close(fd[0]), exit(1), -1);
	if ((argc > 5 && here_doc == FALSE) || (argc > 6 && here_doc == TRUE))
		fd[0] = mid_execve(argv, env, fd, argc);
	wait(NULL);
	last_execve(argv, env, fd, argc);
	return (0);
}