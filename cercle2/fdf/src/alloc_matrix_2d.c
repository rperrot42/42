/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_matrix_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:41:39 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/05 11:41:39 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bool	alloc_matrix_2d(t_all_matrix *all_matrix)
{
	int	i;
	int	height;

	all_matrix -> display_matrix = malloc(sizeof (t_display_matrix));
	if (!all_matrix -> display_matrix)
		return (FALSE);
	all_matrix -> display_matrix->width = all_matrix ->matrix_3_d->width;
	all_matrix -> display_matrix->height = all_matrix ->matrix_3_d->height;
	height = all_matrix ->matrix_3_d->height;
	all_matrix -> display_matrix -> display_pixel = \
malloc(sizeof(t_point_3d *) * height);
	if (!all_matrix -> display_matrix -> display_pixel)
		return (free(all_matrix -> display_matrix), \
all_matrix -> display_matrix = NULL, FALSE);
	i = -1;
	while (++i < height)
	{
		all_matrix ->display_matrix->display_pixel[i] = \
malloc(sizeof(t_point_3d) * all_matrix->matrix_3_d->width);
		if (!all_matrix ->display_matrix->display_pixel[i])
			return (free_display_matrix(all_matrix ->display_matrix), \
all_matrix ->display_matrix = NULL, FALSE);
	}
	return (TRUE);
}