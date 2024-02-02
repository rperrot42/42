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


void write_bonjour_in_main();
int main (int argc, char **argv, char **env)
{
	//exec_cmd(argv[1], env);
	pipep(argc, argv, env);

}
