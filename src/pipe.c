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
	int 	fd_in;
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
		fprintf(file_ptr, "bonjour %d\n", getpid());
		//fprintf(file_ptr, "fd de 1: %d\n", fd[1]);
		close(fd_file_exit);
		close(fd[0]);
		dup2(fd_file_enter, 0);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd_file_enter);
		exec_cmd(argv[2], env);
	}
	fd_in = fd[0];
	close(fd[1]);
	i = 2;
	while (++i < argc - 2)
	{
		pipe(fd);
		pid = fork();
        //fprintf(file_ptr, "%d %d\n", fd[0], fd[1]);
        pipe(fd);
		if (pid == 0)
		{
			sleep(2);
			fprintf(file_ptr, "bonjour je suis celui du milieu %d\n", getpid());
			//fprintf(file_ptr, "%d %d\n", fd[0], fd[1]);
            dup2(fd_in, 0);
            dup2(fd[1], 1);
			close(fd[1]);
			close(fd[0]);
			close(fd_in);
            close(fd_file_enter);
            close(fd_file_exit);
            exec_cmd(argv[i], env);
		}
		close(fd_in);
		fd_in = fd[0];
		close(fd[1]);
	}
	//ft_printf("fd de 0: %d\n", fd[0]);
    //fprintf(file_ptr, "%d %d\n", fd[0], fd[1]);
	close(fd_file_enter);
	dup2(fd[0], 0);
	dup2(fd_file_exit, 1);
	close(fd[0]);
	close(fd_file_exit);
	exec_cmd(argv[argc - 2], env);
	return (0);
}