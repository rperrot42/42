/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:30:23 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/15 15:30:34 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

void	read_file_fdf(char *name_file, t_vars *vars)
{
	int		fd;
	char	*line;
	int 	i;

	fd = open(name_file, O_RDONLY);
	if (fd == -1)
		close_vars(vars);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

int *count_line(char *name_file, t_vars *vars)
{
	int		fd;
	int		x_y[2];
	char	c[1000];
	int		r;

	fd = open(name_file, O_RDONLY);
	if (fd == -1)
		close_vars(vars);
	x_y[0] = 0;
	if (read(fd, c, 1) < 0)
		close_vars(vars);
	while (*c && *c !='\n')
	{
		if (*c == ' ')
			x_y[0] += 1;
		r = read(fd, c, 1);
		if (r < 0)
			close_vars(vars);
		else if (r == 0)
			*c = 0;
	}
	if (*c != '\n')
	{
		x_y[1] = 1;
		return (x_y);
	}

}