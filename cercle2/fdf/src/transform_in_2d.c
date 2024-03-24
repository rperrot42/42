/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_in_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:02:37 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/12 19:46:52 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point_3d	create_point_2d(t_point_z point_z, short x, short y, \
t_display_info *display_info);

static unsigned int	create_color_point(short z, t_display_info *display_info, \
int actual_color);

static unsigned int	create_avanc_color(short z, unsigned int \
color1, unsigned int color2, short diff_z);

void	transforme_matrix_3d_in2d(t_all_matrix *all_matrix, \
t_display_info *display_info)
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
		while (++j < width)
			all_matrix->display_matrix->display_pixel[i][j] = \
create_point_2d(all_matrix->matrix_3_d->matrix_point[i][j], j, i, display_info);
	}
}

static t_point_3d	create_point_2d(t_point_z point_z, \
short x, short y, t_display_info *display_info)
{
	t_point_3d	new_point_2d;
	float		coords[3];
	float		result[3];

	coords[0] = x - display_info-> width / 2;
	coords[1] = y - display_info-> height / 2;
	coords[2] = point_z.z * display_info->multiplier_value_z;
	multiplication_matrix_3x1(display_info->rotation_vector, coords, result);
	if (display_info -> projection_type == PERSPECTIVE)
		new_point_2d = perspective_projection(result, display_info);
	else if (display_info -> projection_type == STEREOGRAPHIC)
		new_point_2d = stereographic_projection(result, display_info);
	else
		new_point_2d = isometrique_projection(result, display_info);
	if (point_z.color)
		new_point_2d.color = point_z.color;
	else
		new_point_2d.color = create_color_point(point_z.z, \
		display_info, display_info->actual_color);
	return (new_point_2d);
}

static unsigned int	create_color_point(short z, t_display_info *display_info, \
int actual_color)
{
	unsigned int	color;

	if (z < 0)
		color = create_avanc_color(z * -1, \
display_info->color_null[actual_color], \
display_info->color_negative[actual_color], display_info->point_min * -1);
	else if (z >= 0 && z <= display_info->point_max / 6)
		color = create_avanc_color(z, display_info->color_null[actual_color], \
		display_info->color_mid[actual_color], display_info->point_max / 4);
	else
		color = create_avanc_color(z - display_info->point_max / 6, \
		display_info->color_mid[actual_color], \
		display_info->color_max[actual_color], \
		5 * display_info->point_max / 6 + display_info->point_max % 6);
	return (color);
}

static unsigned int	create_avanc_color(short z, unsigned int color1, \
unsigned int color2, short diff_z)
{
	int				i;
	short			difference_color;
	unsigned int	color_final;

	color_final = color1;
	if (diff_z != 0)
	{
		i = -1;
		color_final = color1;
		while (++i < 4)
		{
			difference_color = ((color2 >> (8 * i)) & 255) - \
			((color1 >> (8 * i)) & 255);
			color_final += (difference_color * z / diff_z) << (8 * i);
		}
	}
	return (color_final);
}

void	change_display_matrix(t_display_matrix *display_matrix, \
short x, short y)
{
	int	i;
	int	j;

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
