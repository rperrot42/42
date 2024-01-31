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
	exec_cmd(argv[1], env);
	//write_bonjour_in_main();
	/*int fd[2];
	char buffer[70];
	int stdin;
	int stdout;

	pid_t pid;
	pipe(fd);
	pid = fork();
	stdin = dup(0);
	stdout = dup(1);
	printf("Mon PID est %d\n", getpid());
	if (pid > 0) {

		dup2( fd[1], 1);
		dup2( fd[0], 0);

		read(0, buffer, 70);
		write(stdout, buffer, 70);
		close(fd[0]);
		close(fd[1]);
		close(stdout);
		close(stdin);
		int a;
		wait(&a);
	}
	else if (pid == 0) {

		dup2(fd[1], 1);
		dup2(fd[0], 0);
		//pid = fork();
		char **elmnt_path;

		elmnt_path = ft_split(env[search_path_env(env)] + 5, ':');
		while (*elmnt_path && access(ft_strjoin_three(*elmnt_path, "/", argv[1]), X_OK))
			elmnt_path++;
		//write(stdout, ft_strjoin_three(*elmnt_path, "/", argv[1]),15);
		ft_printf("execve %d\n",execve(ft_strjoin_three(*elmnt_path, "/", argv[1]), argv + 1, NULL));
	 */
		/*
		if (pid == 0) {
			ft_printf("je suis le fils du fils\n");
			sleep(2);
		} else if (pid > 0) {
			ft_printf("je suis le fils\n");
			wait(&status);
		}*/

	return (0);

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
