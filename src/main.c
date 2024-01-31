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
void write_bonjour_in_main()
{
	int fd;
	char buffer[4];
	printf("Mon PID est %d\n", getpid());
	fd = open("src/main.c", O_RDWR);
	//dup2(fd, 1);
	ft_printf("%dbonjour", fd);
	ft_printf("%d\n", read(fd, buffer, 4));
	write(1, "bonjour", 7);
	while (42)
		;
}
