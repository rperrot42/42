/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:49:50 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/17 01:49:50 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point_3d	perspective_projection(float coordinates_point[3], \
t_display_info *display_info)
{
	t_point_3d	new_point_2d;
	float		x;
	float		y;

	coordinates_point[2] = coordinates_point[2] + display_info->distance_z_min;
	x = coordinates_point[0] * display_info -> distance_point \
	* display_info->result_pov;
	y = coordinates_point[1] * display_info -> distance_point \
	* display_info->result_pov;
	if (coordinates_point[2] <= 1)
		coordinates_point[2] = 1;
	new_point_2d.z = coordinates_point[2];
	new_point_2d.x = x / coordinates_point[2] + WIDTH / 2 + \
	display_info->move_x;
	new_point_2d.y = y / coordinates_point[2] + HEIGHT / 2 \
	+ display_info->move_y;
	return (new_point_2d);
}

t_point_3d	stereographic_projection(float coordinates_point[3], \
t_display_info *display_info)
{
	t_point_3d	new_point_2d;
	float		x;
	float		y;
	float		y_absolute;

	coordinates_point[2] = coordinates_point[2] + display_info->distance_z_min;
	x = coordinates_point[0] * display_info -> distance_point \
	* display_info->result_pov;
	y = coordinates_point[1] * display_info->distance_point \
	* display_info->result_pov;
	y_absolute = coordinates_point[1];
	if (y < 0)
		y_absolute *= -1;
	new_point_2d.x = x * cosf(M_PI * y_absolute / (display_info->height_max \
	-1)) / coordinates_point[2] + WIDTH / 2 + display_info->move_x;
	new_point_2d.y = y / coordinates_point[2] + HEIGHT / 2 \
	+ display_info->move_y;
	new_point_2d.z = coordinates_point[2];
	return (new_point_2d);
}
