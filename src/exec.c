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

int exec_cmd(char *cmd, char **env)
{
	char	**elmnt_path;
	char	*path_test;
	char	**arg;

	arg = ft_split(cmd,' ');
	elmnt_path = ft_split(env[search_path_env(env)] + 5, ':');
	path_test = ft_strjoin_three(*elmnt_path, "/", arg[0]);
	if (!path_test)
		return (1);
	while (*elmnt_path && access(path_test, X_OK))
	{
		free(path_test);
		elmnt_path++;
		if (*elmnt_path)
			path_test = ft_strjoin_three(*elmnt_path, "/", arg[0]);
		if (!path_test)
			return (1);
	}
	return (execve(path_test, arg, env));
}

static int	search_path_env(char **env)
{
	int i;

	i = 0;
	while (env[i] && ft_strncmp("PATH", env[i], 4))
		i++;
	return (i);
}
