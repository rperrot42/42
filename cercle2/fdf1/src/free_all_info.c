/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:07:59 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/03 13:07:59 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

void	free_matrix_3d(t_matrix_3d *matrix_3d)
{
	int	i;

	i = -1;
	while (++i < matrix_3d -> height)
		free(matrix_3d ->matrix_point[i]);
	free(matrix_3d -> matrix_point);
	free(matrix_3d);
}

void	free_display_matrix(t_display_matrix *display_matrix)
{
	int	i;

	i = -1;
	while (++i < display_matrix -> height)
	{
		if (!display_matrix->display_pixel[i])
			break;
		free(display_matrix->display_pixel[i]);
	}
	free(display_matrix ->display_pixel);
	free(display_matrix);
}
