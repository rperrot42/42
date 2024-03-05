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

static t_bool	add_elmnt_lst_file(int fd, t_list **lst_file);

static t_matrix_3d 	*create_matrix_point3d(t_list **lst_file, int height);

t_matrix_3d 	*read_file_fdf(char *name_file)
{
	int		fd;
	t_bool	is_finish;
	t_list	*lst_file;
	int	i;

	lst_file = NULL;
	fd = open(name_file, O_RDONLY);
	i = 0;
	if (fd == -1)
		(exit(1));
	is_finish = FALSE;
	while (is_finish == FALSE && ++i)
		is_finish = add_elmnt_lst_file(fd, &lst_file);
	if (close(fd) == -1)
		return (ft_lstclear(&lst_file, free), NULL);
	return (create_matrix_point3d(&lst_file, i - 1));
}

static t_bool	add_elmnt_lst_file(int fd, t_list **lst_file)
{
	char	*line;
	t_list	*line_file;

	line = get_next_line(fd);
	if (!line)
		return TRUE;
	line_file = ft_lstnew(line);
	if (!line_file)
	{
		close(fd);
		free(line);
		ft_lstclear(lst_file, free);
		exit(1);
	}
	ft_lstadd_back(lst_file, line_file);
	return FALSE;
}

static int size_line(char *line)
{
	int nb_space;

	nb_space = 0;
	while (*line == ' ')
		line++;
	while (*line) {
		if (*line == ' ')
		{
			while (*line == ' ')
				line++;
			nb_space++;
		}
		line++;
	}
	return (++nb_space);
}

static t_point_z *create_line_3d(char *line, int width)
{
	t_point_z *line_point;
	int i;

	line_point = malloc(width * sizeof(t_point_z));
	if (!line_point)
		return (NULL);
	i = -1;
	while (++i < width)
		line_point[i] = create_point3d(&line);
	return (line_point);
}

static t_matrix_3d 	*create_matrix_point3d(t_list **lst_file, int height)
{
	t_matrix_3d		*matrix_3d;
	int				width;
	int 			i;
	t_list 			*first_line;

	matrix_3d = malloc(sizeof (matrix_3d));
	first_line = *lst_file;
	if (!matrix_3d)
		return (ft_lstclear(&first_line, free), NULL);
	matrix_3d -> matrix_point = malloc(height * sizeof(t_point_3d *));
	if (!matrix_3d->matrix_point)
		return (ft_lstclear(&first_line, free), NULL);
	width = size_line((char *)(*lst_file) -> content);
	i = -1;
	while (++i < height)
	{
		matrix_3d -> matrix_point[i] = create_line_3d((char *)(*lst_file) -> content, width);
		if (!matrix_3d -> matrix_point[i])
			return (ft_lstclear(&first_line, free), free_matrix_3d(matrix_3d), NULL);
		*lst_file = (*lst_file) -> next;
	}
	matrix_3d -> width = width;
	matrix_3d -> height = height;
	ft_lstclear(&first_line, free);
	return (matrix_3d);
}
