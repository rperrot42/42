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


int main (int argc, char **argv, char **env)
{
	errno = 0;
	t_pipex pipex;

	pipex.here_doc = FALSE;
	pipex.env = env;
	pipex.argv = argv;
	pipex.argc = argc;
	if (!ft_strncmp("here_doc", argv[1], 9))
		pipex.here_doc  = TRUE;
	if ((argc >= 5 && pipex.here_doc  == FALSE) || (argc >= 6 && pipex.here_doc  == TRUE))
		pipep(&pipex);
	else
	{
		perror("Error: Insufficient arguments provided. Please provide the required arguments.");
		return (1);
	}
	return (0);
}
