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

static t_bool is_displayable(t_point_3d point_a, t_point_3d point_b);

static void	print_point(t_point_3d display_point, t_img_info *img_info, t_bool black_color);

void	print_all_ligne(t_display_matrix *display_matrix, t_img_info *img, t_bool black_color, t_bool is_print_point)
{
	int	i;
	int j;

	i = -1;

	while (++i < display_matrix -> height)
	{
		j = -1;
		while (++j < display_matrix -> width)
		{
			if (i && is_displayable(display_matrix->display_pixel[i][j], display_matrix->display_pixel[i - 1][j]) == TRUE)
			{
				if (is_print_point == FALSE)
					create_line_all(img, display_matrix->display_pixel[i][j], display_matrix->display_pixel[i - 1][j],
									black_color);
				else
				{
					print_point(display_matrix->display_pixel[i][j], img,black_color);
					print_point(display_matrix->display_pixel[i - 1][j], img,black_color);
				}
			}
			if (j && is_displayable(display_matrix->display_pixel[i][j], display_matrix->display_pixel[i][j - 1]) == TRUE)
			{
				if (is_print_point == FALSE)
					create_line_all(img, display_matrix->display_pixel[i][j], display_matrix->display_pixel[i][j - 1],
									black_color);
				else
				{
					print_point(display_matrix->display_pixel[i][j], img,black_color);
					print_point(display_matrix->display_pixel[i][j - 1], img,black_color);
				}
			}
		}
	}
}

static t_bool is_displayable(t_point_3d point_a, t_point_3d point_b)
{
	if ((point_a.x >= WIDTH && point_b.x >= WIDTH) || (point_a.x <= 0 && point_b.x <= 0) || (point_a.y >= HEIGHT && point_b.y >= HEIGHT) || (point_a.y <= 0 && point_b.y <= 0))
		return (FALSE);
	return (TRUE);
}

static void	print_point(t_point_3d display_point, t_img_info *img_info, t_bool black_color)
{
	if (display_point.x < 0 || display_point.x >= WIDTH || display_point.y < 0 || display_point.y >= HEIGHT)
		return;
	if (black_color == FALSE)
	{
		if (img_info->distance_pixel[display_point.y][display_point.x] > display_point.z)
		{
			img_info->distance_pixel[display_point.y][display_point.x] = display_point.z;
			my_mlx_pixel_put(img_info, display_point.x, display_point.y, display_point.color);
		}
	}
	else
	{
		img_info->distance_pixel[display_point.y][display_point.x] = FLT_MAX;
		my_mlx_pixel_put(img_info, display_point.x, display_point.y, 0);
	}
}