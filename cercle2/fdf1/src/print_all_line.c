/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:15:14 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/05 18:15:14 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

void	print_all_ligne(t_display_matrix *display_matrix, t_data *img)
{
	int	i;
	int j;

	i = -1;
	while (++i < display_matrix ->height)
	{
		j = -1;
		while (++j < display_matrix ->width)
		{
			if (i)
				create_line_all(img,display_matrix->display_pixel[i][j], display_matrix->display_pixel[i - 1][j]);
			if (j)
				create_line_all(img,display_matrix->display_pixel[i][j - 1], display_matrix->display_pixel[i][j]);
		}
	}
}