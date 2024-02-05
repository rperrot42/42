#ifndef PIPEX_PIPEX_H
#define PIPEX_PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include "./../libft/libft.h"
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
int	exec_cmd(char *cmd, char **env);
int	pipep(int argc, char **argv, char **env, t_bool here_doc);
#endif
