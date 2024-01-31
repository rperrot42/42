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

int	pipep(int argc, char **argv, char **env)
{
	int		fd_file_enter;
	int		fd_file_exit;
	pid_t	pid;
	int		fd[2];
	//int 	fd_mixt;
	int		i;

	fd_file_enter = open(argv[1], O_RDONLY);
	fd_file_exit = open(argv[argc - 1], O_WRONLY);
	pipe(fd);
	pid = fork();
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
		if (pid == 0)
		{
			/*pipe(fd);
			dup2(fd[0], 0);
			dup2(fd[1], 1);
			exec_cmd(argv[i], env);*/
			ft_printf("%d i\n", i);
			return (0);
		}
	}

	wait(NULL);
	close(fd_file_enter);
	close(fd[1]);
	dup2( fd[0], 0);
	dup2(fd_file_exit, 1);
	exec_cmd(argv[argc - 2], env);
	return (0);
}