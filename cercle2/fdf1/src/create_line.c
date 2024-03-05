/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:18:44 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/12 18:18:44 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

static void swap_point(t_point_3d *a, t_point_3d *b, t_info_segment *info_segment);

static void init_info_segment(t_point_3d *a, t_point_3d *b, t_info_segment *info_segment);

static void create_line(t_data *img, t_point_3d *a, t_point_3d *b, t_info_segment *inf_seg);

void	create_line_all(t_data *img, t_point_3d a, t_point_3d b)
{
	t_info_segment info_segment;
	init_info_segment(&a, &b, &info_segment);
	if (info_segment.dx > 0)
	{
		init_color_line(&a, &b, &info_segment);
		create_line(img, &a, &b, &info_segment);
	}
	else
	{
		info_segment.dy = a.y - b.y;
		info_segment.dx = a.x - b.x;
		info_segment.avanc = (info_segment.dy >= 0) - (info_segment.dy < 0);
		init_color_line(&b, &a, &info_segment);
		create_line(img, &b, &a, &info_segment);
	}
}

static void	create_line(t_data *img, t_point_3d *a, t_point_3d *b, t_info_segment *inf_seg)
{
	a->x = a->x - 1;
	while (++a->x <= b->x)
	{
		inf_seg->eps += inf_seg->dy * inf_seg->avanc;
		if (inf_seg->dy_is_sup_dx == TRUE)
			my_mlx_pixel_put(img, a->y, a->x, a->color);
		else
			my_mlx_pixel_put(img, a->x, a->y, a->color);
		if (inf_seg->eps * 2 > inf_seg->dx)
		{
			inf_seg->eps -= inf_seg->dx;
			a->y += inf_seg->avanc;
		}
		create_color_line(a, inf_seg);
	}
}

static void swap_point(t_point_3d *a, t_point_3d *b, t_info_segment *info_segment)
{
	short	swap;

	swap = a->x;
	a->x = a->y;
	a->y = swap;
	swap = b->x;
	b->x = b->y;
	b->y = swap;
	info_segment->dy = b->y - a->y;
	info_segment->dx = b->x - a->x;
	info_segment->avanc = (info_segment->dy >= 0) - (info_segment->dy < 0);
	info_segment->dy_is_sup_dx = TRUE;
}

static void init_info_segment(t_point_3d *a, t_point_3d *b, t_info_segment *info_segment)
{

	info_segment -> eps = 0;
	info_segment->dy = b->y - a->y;
	info_segment->dx = b->x - a->x;
	info_segment->dy_is_sup_dx = FALSE;
	info_segment->avanc = (info_segment->dy >= 0) - (info_segment->dy < 0);
	if (info_segment->dx * ((info_segment->dx >= 0) - (info_segment->dx < 0)) < info_segment->dy * info_segment->avanc)
		swap_point(a, b, info_segment);
}