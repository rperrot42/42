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
int	pipep(int argc, char **argv, char **env)
{
	int		fd_file_enter;
	int		fd_file_exit;
	pid_t	pid;
	int		fd[2];
	int 	fd_output;
	int		i;
    int stdouut;
    FILE *file_ptr;

    ft_printf("%d\n", getpid());
	fd_file_enter = open(argv[1], O_RDONLY);
	fd_file_exit = open(argv[argc - 1], O_WRONLY);
	pipe(fd);
	pid = fork();
    stdouut = dup(1);
    file_ptr = fdopen(stdouut, "w");
	//stdout = dup(1);
	if (pid == 0) {
		close(fd_file_exit);
		close(fd[0]);
		dup2(fd_file_enter, 0);
		dup2(fd[1], 1);

		exec_cmd(argv[2], env);
		return (0);
	}
	i = 2;
	while (++i < argc - 2)
	{
		pid = fork();
        fprintf(file_ptr, "%d %d\n", fd[0], fd[1]);
        fd_output = fd[1];
        pipe(fd);
        close(fd[0]);
        fd[0] = fd_output;
		if (pid == 0)
		{
            dup2(fd[0], 0);
            dup2(fd[1], 1);
            close(fd_file_enter);
            close(fd_file_exit);
            exec_cmd(argv[i], env);
		}
	}
    fprintf(file_ptr, "%d %d\n", fd[0], fd[1]);
	close(fd_file_enter);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(fd_file_exit, 1);
	exec_cmd(argv[argc - 2], env);
	return (0);
}