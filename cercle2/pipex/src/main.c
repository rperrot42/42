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
	t_bool here_doc;

	here_doc = FALSE;
	if (!ft_strncmp("here_doc", argv[1], 9))
		here_doc = TRUE;
	if ((argc >= 5 && here_doc == FALSE) || (argc >= 6 && here_doc == TRUE))
		pipep(argc, argv, env, here_doc);
	else {
		perror("Error: Insufficient arguments provided. Please provide the required arguments.");
		return (1);
	}
	return (0);
}
