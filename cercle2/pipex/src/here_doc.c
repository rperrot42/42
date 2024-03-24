/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:44:57 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/23 18:44:57 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int			create_name(char **name, int fd1);

void		replace_slash(char *str);

static void	heredoc_err(char *name, t_bool unlink_name, int fd1, \
int fd_file_enter);

void	read_here_doc(char *limiter, int *fd_enter, int fd1)
{
	char	*line;
	char	*name;

	*fd_enter = create_name(&name, fd1);
	line = get_next_line(0);
	if (!line)
		return (heredoc_err(name, TRUE, fd1, *fd_enter), exit(EXIT_MALLOC));
	while (ft_findnewline(line) <= 1 || \
ft_strncmp(line, limiter, ft_findnewline(line) - 1))
	{
		if (ft_strncmp(line, limiter, ft_findnewline(line) - 1))
			write(*fd_enter, line, ft_findnewline(line));
		free(line);
		line = get_next_line(0);
		if (!line)
			return (heredoc_err(name, TRUE, fd1, *fd_enter), exit(EXIT_MALLOC));
	}
	free(line);
	close(*fd_enter);
	*fd_enter = open(name, O_RDONLY | O_CREAT);
	if (*fd_enter == -1)
		return (heredoc_err(name, TRUE, fd1, 0), exit(EXIT_OPEN_FAIL));
	if (unlink(name) == -1)
		return (heredoc_err(name, FALSE, fd1, *fd_enter), exit(EXIT_UNLINK));
	free(name);
}

int	create_name(char **name, int fd1)
{
	int	fd_open;

	fd_open = open(FILE_RANDOM, O_RDONLY);
	if (fd_open == -1)
		return (close(fd1), exit(EXIT_OPEN_FAIL), 0);
	*name = malloc(sizeof(char) * 25);
	if (!(*name))
		return (close(fd_open), close(fd1), exit(EXIT_MALLOC), 0);
	if (read(fd_open, *name, 24) == -1)
	{
		free(*name);
		close(fd_open);
		close(fd1);
		exit(EXIT_READ_FAIL);
	}
	close(fd_open);
	(*name)[24] = 0;
	replace_slash(*name);
	fd_open = open(*name, O_WRONLY | O_CREAT, 0777);
	if (fd_open == -1)
		return (free(*name), close(fd1), exit(EXIT_MALLOC), 0);
	return (fd_open);
}

void	replace_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			str[i] = 'A';
		i++;
	}
}

static void	heredoc_err(char *name, t_bool unlink_name, int fd1, \
int fd_file_enter)
{
	if (name)
	{
		if (unlink_name == TRUE)
			unlink(name);
		free(name);
	}
	close(fd1);
	if (fd_file_enter)
		close(fd_file_enter);
}
