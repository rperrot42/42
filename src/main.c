/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:05:37 by rperrot           #+#    #+#             */
/*   Updated: 2024/01/30 13:05:37 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/pipex.h"

int	search_path_env(char **env);

int main (int argc, char **argv, char **env)
{
	//char *envp[] = {NULL};

	//pid_t pid;
	char **elmnt_path;

	elmnt_path = ft_split(env[search_path_env(env)] + 5, ':');
	while (*elmnt_path && access(ft_strjoin_three(*elmnt_path, "/", argv[1]), X_OK))
		elmnt_path++;
	execve(ft_strjoin_three(*elmnt_path, "/", argv[1]), argv+1, NULL);
}

int	search_path_env(char **env)
{
	int i;

	i = 0;
	while (env[i] && ft_strncmp("PATH", env[i], 4))
		i++;
	return (i);
}
