/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_in_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:02:37 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/04 19:02:37 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

static t_point_3d 	create_point_2d(t_point_z point_z, short x, short y);

void	transforme_matrix_3d_in2d(t_all_matrix *all_matrix)
{
	short	i;
	short	j;
	short	height;
	short	width;

	i = -1;
	height = all_matrix ->display_matrix ->height;
	width = all_matrix -> display_matrix ->width;
	while (++i < height)
	{
		j = -1;
		while(++j < width)
			all_matrix->display_matrix->display_pixel[i][j] = create_point_2d(all_matrix ->matrix_3_d->matrix_point[i][j], j, i);
	}
}

static t_point_3d 	create_point_2d(t_point_z point_z, short x, short y)
{
	t_point_3d	new_point_2d;

	ft_printf("%d  %d %d %d\n",  WIDTH/HEIGHT, point_z.z, x +1, y);
	new_point_2d.x = 100 * WIDTH * (x * 30 + 1)/ (((point_z.z * 2 * (x *30 -360)) / 360 + 100) * HEIGHT);
	new_point_2d.y = 100 * (y * 30 + 1) / ((point_z.z * 2 * (y *30 -180)) / 180 + 100);
	new_point_2d.color = 0x00FF0000 + point_z.z/10*0x00FFFF;
	return (new_point_2d);
}