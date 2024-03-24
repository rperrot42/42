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

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex		pipex;
	int			back_value_pipep;

	pipex.here_doc = FALSE;
	pipex.env = env;
	pipex.argv = argv;
	pipex.argc = argc;
	pipex.indice_pid = -1;
	if (argc >= 2 && !ft_strncmp(HERE_DOC, argv[1], ft_strlen(HERE_DOC) + 1))
		pipex.here_doc = TRUE;
	if (argc - (pipex.here_doc == TRUE) >= 5)
	{
		back_value_pipep = ft_pipex(&pipex);
		wait_all_pid(&pipex);
		print_error(back_value_pipep, &pipex, 0);
	}
	else
	{
		ft_putstr_fd(ERROR_ARGS, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
