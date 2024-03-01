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

static

static t_bool	add_elmnt_lst_file(int fd, t_vars *vars, t_list **lst_file);

t_list 	*read_file_fdf(char *name_file, t_vars *vars)
{
	int		fd;
	t_bool	is_finish;
	t_list	*lst_file;
	int	i;

	lst_file = NULL;
	fd = open(name_file, O_RDONLY);
	i = 0;
	if (fd == -1)
		close_vars(vars);
	is_finish = FALSE;
	while (++i && is_finish == FALSE)
		is_finish = add_elmnt_lst_file(fd, vars, &lst_file);
	return (lst_file);
}

static t_bool	add_elmnt_lst_file(int fd, t_vars *vars, t_list **lst_file)
{
	char	*line;
	t_list	*line_file;

	line = get_next_line(fd);
	if (!line)
		return TRUE;
	line_file = ft_lstnew(line);
	if (!line_file)
	{
		ft_lstclear(lst_file, free);
		close_vars(vars);
	}
	ft_lstadd_back(lst_file, line_file);
	return FALSE;
}

static int size_line(char *line)
{
	int nb_space;

	nb_space = 0;
	while (*line) {
		if (*line == ' ')
			nb_space++;
		line++;
	}
	return (++nb_space);
}

static t_point_3d *create_line_3d(char *line, int width)
{
	t_point_3d *line_point;
	int i;

	line_point = malloc(width * sizeof(t_point_3d));
	if (!line_point)
		return (NULL);
	i = -1;
	while (++i < width)
	{
		line_point[i].z = ft_atoi(line);
	}

}
static t_point_3d	**create_matrix_point3d(t_list **lst_file, int height)
{

}
