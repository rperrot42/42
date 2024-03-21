/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:10:15 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/31 14:10:15 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/pipex.h"

static int	search_path_env(char **env);

static void	error_execve(char *path_test, char *cmd, char **arg, char **elmnt_path);

static void free_split(char **split);

static void clean_execve(char *path_test, char **arg, char **elmnt_path);

int exec_cmd(char *cmd, char **env)
{
	char	**elmnt_path;
	char	*path_test;
	char	**arg;
	int		i;
	int		result_search_path_env;

	elmnt_path = NULL;
	arg = ft_split(cmd,' ');
	if (!arg || !*arg)
		error_execve(NULL, cmd, arg, NULL);
	if (!access(arg[0], X_OK))
		path_test = arg[0];
	else
	{
		if (!*env)
			error_execve(NULL, cmd, arg, NULL);
		result_search_path_env= search_path_env(env);
		if (result_search_path_env == -1)
			error_execve(NULL, cmd, arg,NULL);
		elmnt_path = ft_split(env[result_search_path_env] + 5, ':');
		path_test = ft_strjoin_three(*elmnt_path, "/", arg[0]);
		if (!path_test)
			clean_execve(path_test, arg, elmnt_path);
		i = -1;
		while (elmnt_path[++i] && access(path_test, X_OK))
		{
			free(path_test);
			path_test = NULL;
			if (*elmnt_path)
			{
				path_test = ft_strjoin_three(elmnt_path[i], "/", arg[0]);
				if (!path_test)
					clean_execve(path_test, arg, elmnt_path);
			}
		}
	}
	if (access(path_test, X_OK))
		error_execve(path_test, cmd, arg, elmnt_path);
	if (execve(path_test, arg, env) == -1)
		error_execve(path_test, cmd, arg, elmnt_path);
	return(0);
}

static int	search_path_env(char **env)
{
	int i;

	i = 0;
	while (env[i] && ft_strncmp("PATH", env[i], 4))
		i++;
	if (env[i])
		return (i);
	return (-1);
}

static void	error_execve(char *path_test, char *cmd, char **arg, char **elmnt_path)
{
	if (errno == 2 || !*cmd)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(cmd, 2);
		write(2, "\n", 1);
	}
	else
		perror("pipex: ");
	clean_execve(path_test, arg, elmnt_path);
	exit(1);
}

static void clean_execve(char *path_test, char **arg, char **elmnt_path)
{
	close(0);
	close(1);
	if (arg)
		free_split(arg);
	if (elmnt_path)
		free_split(elmnt_path);
	if (path_test)
		free(path_test);
}

static void free_split(char **split)
{
	int i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}