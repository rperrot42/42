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

#include "fdf.h"

static void	print_ligne_possible(t_point_3d point_a, \
t_point_3d point_b, t_print_point info_print_point, t_img_info *img);

static void	print_point(t_point_3d display_point, t_img_info *img_info, \
t_bool black_color);

void	print_all_ligne(t_display_matrix *display_matrix, \
t_img_info *img, t_print_point info_print_point)
{
	int	i;
	int	j;

	i = -1;
	while (++i < display_matrix -> height)
	{
		j = -1;
		while (++j < display_matrix -> width)
		{
			if (info_print_point.is_print_point == TRUE)
				print_point(display_matrix->display_pixel[i][j], \
				img, info_print_point.black_color);
			if (i)
				print_ligne_possible(display_matrix->display_pixel[i][j], \
display_matrix->display_pixel[i - 1][j], info_print_point, img);
			if (j)
				print_ligne_possible(display_matrix->display_pixel[i][j], \
display_matrix->display_pixel[i][j - 1], info_print_point, img);
		}
	}
}

static void	print_ligne_possible(t_point_3d point_a, \
t_point_3d point_b, t_print_point info_print_point, t_img_info *img)
{
	if ((point_a.x >= WIDTH && point_b.x >= WIDTH) || (point_a.x <= 0 && \
	point_b.x <= 0) || (point_a.y >= HEIGHT && point_b.y >= HEIGHT) || \
	(point_a.y <= 0 && point_b.y <= 0))
		return ;
	if (info_print_point.is_print_point == FALSE)
		create_line_all(img, point_a, point_b, info_print_point.black_color);
	else
		print_point(point_b, img, info_print_point.black_color);
}

static void	print_point(t_point_3d display_point, t_img_info *img_info, \
t_bool black_color)
{
	if (display_point.x < 0 || display_point.x >= WIDTH || \
	display_point.y < 0 || display_point.y >= HEIGHT)
		return ;
	if (black_color == FALSE)
	{
		if (img_info->distance_pixel[display_point.y][display_point.x] > \
		display_point.z)
		{
			img_info->distance_pixel[display_point.y][display_point.x] = \
			display_point.z;
			my_mlx_pixel_put(img_info, display_point.x, display_point.y, \
			display_point.color);
		}
	}
	else
	{
		img_info->distance_pixel[display_point.y][display_point.x] = INT_MAX;
		my_mlx_pixel_put(img_info, display_point.x, display_point.y, 0);
	}
}
