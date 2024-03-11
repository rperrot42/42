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

static t_point_3d 	create_point_2d(t_point_z point_z, short x, short y, t_display_info *display_info);

void	transforme_matrix_3d_in2d(t_all_matrix *all_matrix, t_display_info *display_info)
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
			all_matrix->display_matrix->display_pixel[i][j] = create_point_2d(all_matrix ->matrix_3_d->matrix_point[i][j], j, i, display_info);
	}
}

static t_point_3d 	create_point_2d(t_point_z point_z, short x, short y, t_display_info *display_info)
{
	float x1;
	float y2;
	t_point_3d	new_point_2d;


	point_z.z = 0;
	float a[3] = {x - display_info-> width / 2, y -  display_info-> height / 2 ,point_z.z};
	float result[3];
	multiplication_matrix_3x1(display_info->rotation_vector, a, result);
	result[2] = result[2]  + display_info->distance_z_min  + result[2] * display_info ->multiplier_value_z;
	x1 = result[0] * display_info -> distance_point;
	y2 = result[1] * display_info -> distance_point;
	if (result[2] <= 0.1)
	{
		new_point_2d.x = -1;
		new_point_2d.y = -1;
	}
	else
	{
		new_point_2d.x = x1 / result[2] + WIDTH / 2 - WIDTH * 0.15 + display_info->move_x;
		new_point_2d.y = y2 / result[2] + HEIGHT / 2 + HEIGHT * 0.15 + display_info->move_y;
		new_point_2d.color = point_z.z / 10 * 0xFFFF + 0xFF0000;
	}
	return (new_point_2d);
}

void change_display_matrix(t_display_matrix *display_matrix, short x, short y)
{
	int i;
	int j;

	i = -1;
	while (++i < display_matrix->height)
	{
		j = -1;
		while (++j < display_matrix->width)
		{
			display_matrix->display_pixel[i][j].x += x;
			display_matrix->display_pixel[i][j].y += y;
		}
	}
}
