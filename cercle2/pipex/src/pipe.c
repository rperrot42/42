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
		return (close(fd_rand), exit(1));
	if (read(fd_rand, *name, 24) == -1)
	{
		free(*name);
		close(fd_rand);
		exit(1);
	}
	close(fd_rand);
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
			return (close(*fd_file_enter), free(name), exit(1));
	}
	free(line);
	close(*fd_file_enter);
	*fd_file_enter = open(name,  O_RDONLY | O_CREAT);
	free(name);
	if (*fd_file_enter == -1)
		return (exit(1));
	unlink(name);
}

void first_execve(t_pipex *pipex)
{
	int	fd_file_enter;

	if (pipex->here_doc == FALSE)
		fd_file_enter = open(pipex->argv[1], O_RDONLY);
	else
		read_here_doc(pipex->argv[2], &fd_file_enter);
	if (fd_file_enter == -1)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putstr_fd(pipex->argv[1], 2);
		ft_putstr_fd("\n", 2);
	}
	close(pipex->fd[0]);
	if (dup2(fd_file_enter, 0) == -1)
		return (close(fd_file_enter), close(pipex->fd[1]), exit(1));
	if (dup2(pipex->fd[1], 1) == -1)
		return (close(fd_file_enter), close(0), close(pipex->fd[1]),  exit(1));
	close(fd_file_enter);
	close(pipex->fd[1]);
	if (pipex->here_doc == FALSE)
		exec_cmd(pipex->argv[2], pipex->env);
	else
		exec_cmd(pipex->argv[3], pipex->env);
}

void last_execve(t_pipex *pipex)
{
	int	fd_file_exit;

	fd_file_exit = open(pipex->argv[pipex->argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file_exit == -1)
		return (close(pipex->fd[0]), exit(1));
	if (dup2(pipex->fd[0], 0) == -1)
		return (close(pipex->fd[0]), close(fd_file_exit), exit(1));
	if (dup2(fd_file_exit, 1) == -1)
		return (close(pipex->fd[0]), close(fd_file_exit), close(0), exit(1));
	close(pipex->fd[0]);
	close(fd_file_exit);

	exec_cmd(pipex->argv[pipex->argc - 2], pipex->env);
}

int mid_execve(t_pipex *pipex)
{
	int i;
	int fd_in;
	int	pid;

	i = 2;
	if (!ft_strncmp("here_doc", pipex->argv[1], 9))
		i = 3;
	while (++i < pipex->argc - 2)
	{
		//waitpid(NULL);
		fd_in = pipex->fd[0];
		if (pipe(pipex->fd) == -1)
			return (close(fd_in), exit(1), -1);
		pid = fork();
		if (pid == -1)
			return (close(fd_in), close(pipex->fd[0]), close(pipex->fd[1]), exit(1), -1);
		if (pid == 0)
		{
			close(pipex->fd[0]);
			if (dup2(fd_in, 0) == -1)
				return (close(fd_in), close(pipex->fd[1]), exit(1), -1);
			if (dup2(pipex->fd[1], 1) == -1)
				return (close(fd_in), close(pipex->fd[1]), close(0), exit(1), -1);
			close(pipex->fd[1]);
			close(fd_in);
			exec_cmd(pipex->argv[i], pipex->env);
		}
		close(pipex->fd[1]);
		close(fd_in);
	}
	return (pipex->fd[0]);
}

int	pipep(t_pipex *pipex)
{
	if (pipe(pipex->fd) == -1)
		return (-1);
	pipex->pid = fork();
	if (pipex->pid == -1)
		return (-1);
	if (pipex->pid == 0)
		first_execve(pipex);
	close(pipex->fd[1]);
	if ((pipex->argc > 5 && pipex->here_doc == FALSE) || (pipex->argc > 6 && pipex->here_doc == TRUE))
		pipex->fd[0] = mid_execve(pipex);
	wait(NULL);
	last_execve(pipex);
	return (0);
}