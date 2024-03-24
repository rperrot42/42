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

#include "pipex.h"

static int	search_path_env(char **env);

static void	find_elmnt_path(t_exec_info *exec_info, char **env);

static void	find_path_test(t_exec_info *exec_info, char **env);

int	exec_cmd(char *cmd, char **env)
{
	t_exec_info	exec_info;

	init_exec_info(&exec_info);
	if (!*cmd)
	{
		if (env && *env)
			exit(EXIT_EMPTY_CMD);
		else
			exit(EXIT_ENV);
	}
	exec_info.arg = ft_split(cmd, ' ');
	if (!exec_info.arg || !*(exec_info.arg))
		error_execve(&exec_info, EXIT_MALLOC);
	find_path_test(&exec_info, env);
	if (access(exec_info.path_test, X_OK))
	{
		if (env && *env)
			error_execve(&exec_info, EXIT_CMD_NOT_FOUND);
		else
			error_execve(&exec_info, EXIT_ENV);
	}
	if (execve(exec_info.path_test, exec_info.arg, env) == -1)
		error_execve(&exec_info, EXIT_EXECVE_FAIL);
	return (0);
}

static void	find_elmnt_path(t_exec_info *exec_info, char **env)
{
	if (env && *env)
	{
		exec_info->result_search_path_env = search_path_env(env);
		if (exec_info->result_search_path_env == -1)
			error_execve(exec_info, EXIT_CMD_NOT_FOUND);
		exec_info->elmnt_path = ft_split(\
			env[exec_info->result_search_path_env] + 5, ':');
	}
	else
		exec_info->elmnt_path = ft_split(PATH_DEFAULT + 5, ':');
	if (!exec_info->elmnt_path)
		error_execve(exec_info, EXIT_MALLOC);
}

static t_bool	cmd_is_path_test(t_exec_info *exec_info, char **env)
{
	if (ft_strchr(exec_info->arg[0], '/'))
	{
		if (!access(exec_info->arg[0], X_OK))
			exec_info->path_test = exec_info->arg[0];
		else
		{
			if (!env || !*env)
				error_execve(exec_info, EXIT_ENV);
			else
				error_execve(exec_info, EXIT_CMD_NOT_DIRECTORY);
		}
		return (TRUE);
	}
	return (FALSE);
}

static void	find_path_test(t_exec_info *exec_info, char **env)
{
	int	i;

	if (cmd_is_path_test(exec_info, env) == FALSE)
	{
		find_elmnt_path(exec_info, env);
		exec_info->path_test = ft_strjoin_three(*(\
		exec_info->elmnt_path), "/", exec_info->arg[0]);
		if (!exec_info->path_test)
			error_execve(exec_info, EXIT_MALLOC);
		i = -1;
		while (exec_info->elmnt_path[++i] && access(exec_info->path_test, X_OK))
		{
			free(exec_info->path_test);
			exec_info->path_test = NULL;
			if (*exec_info->elmnt_path)
			{
				exec_info->path_test = ft_strjoin_three(\
				exec_info->elmnt_path[i], "/", exec_info->arg[0]);
				if (!exec_info->path_test)
					error_execve(exec_info, EXIT_MALLOC);
			}
		}
	}
}

static int	search_path_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] && ft_strncmp("PATH", env[i], 4))
		i++;
	if (env[i])
		return (i);
	return (-1);
}
