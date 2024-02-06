/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:33:18 by rperrot           #+#    #+#             */
/*   Updated: 2023/11/24 15:59:58 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	test_gnl(int fd, char *cmp)
{
	char	*gnl;

	gnl = get_next_line(fd);
	free(gnl);
	return (0);
}

int main(){
	int fd = open("read_error.txt", O_RDONLY);
	printf("fd %d\n",fd);

	char *a = get_next_line(fd);
	while (a)
	{
		printf("%s", a);
		free(a);
		a = get_next_line(fd);
	}
	a = get_next_line(fd);
	return (0);
}