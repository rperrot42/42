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
	t_rotation rotation;
	float b[3][3];
	rotation.rotation_x = 0.00;
	rotation.rotation_y = 0;
	create_rotation_matrix(&rotation, b);
	float a[3] = {x, y, point_z.z};
	float result[3];
	x1 = x * display_info -> distance_point - WIDTH/2 + WIDTH *0.15;
	y2 = y * display_info -> distance_point - HEIGHT/2 + HEIGHT * 0.15;
	printf("g %g %g x%d y%d\n",x1, y2, x, y);
	multiplication_matrix_3x1(b, a, result);
	//printf("%g %g %g\n", result[0], result[1], result[2]);
	new_point_2d.x = (WIDTH * x1 / ((point_z.z * display_info ->multiplier_value_z + 1)  * HEIGHT)) + WIDTH /2 - WIDTH*0.15;
	new_point_2d.y =  (y2 / ((point_z.z * display_info ->multiplier_value_z + 1))) + HEIGHT/2 + HEIGHT*0.15;
	new_point_2d.color = 0x00FF0000 + point_z.z/10*0x00FFFF;
	printf("%d %d \n", new_point_2d.x, new_point_2d.y);
	return (new_point_2d);
}