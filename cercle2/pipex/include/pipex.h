#ifndef PIPEX_PIPEX_H
#define PIPEX_PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include "./../libft/libft.h"
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

typedef struct s_pipex
{
	int		fd[2];
	pid_t	pid;
	char	**argv;
	char	**env;
	int		argc;
	t_bool	here_doc;
}	t_pipex;

int	exec_cmd(char *cmd, char **env);
int	pipep(t_pipex *pipex);
int	error_close(int fd);
#endif
