/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:12:25 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/10 19:12:25 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

int create_color(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return ((t << 24) + (r << 16) + (g << 8) + b);
}

void my_mlx_pixel_put(t_img_info *img, int x, int y, unsigned int color)
{
	char *dst;

	dst = img->addr + y * img->line_length + x * img->bits_per_pixel/8;
	*(unsigned int *)dst = color;
}

void 	init_color_line(t_point_3d *a, t_point_3d *b, t_info_segment *info_segment)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		info_segment->eps_color[i] = 0;

		if (((b->color) >> (8 * i) & 255) > ((a->color) >> (8 * i) & 255))
		{
			info_segment->d_color[i] = ((b->color) >> (8 * i) & 255) - ((a->color) >> (8 * i) & 255);
			info_segment->avanc_color[i] = 1;
		}
		else
		{
			info_segment->avanc_color[i] = -1;
			info_segment->d_color[i] =  ((a->color) >> (8 * i) & 255) - ((b->color) >> (8 * i) & 255);
		}
		//ft_printf("%d %d %p %p\n", info_segment->avanc_color[i], info_segment->d_color[i], a->color, b->color);
	}
}

void	create_color_line(t_point_3d *a, t_info_segment *info_segment)
{
	int i;

	i = -1;

	while (++i < 4)
	{
		info_segment->eps_color[i] += info_segment->d_color[i];
		if (info_segment->eps_color[i] * 2 > info_segment->dx)
		{

			a->color += (info_segment->eps_color[i] / info_segment->dx * info_segment->avanc_color[i]) << (8 * i);
			info_segment->eps_color[i] -= info_segment->eps_color[i] / info_segment->dx * info_segment->dx;
			a->color += ((info_segment->eps_color[i] * 2 > info_segment->dx) * info_segment->avanc_color[i] << (8 * i));
			info_segment->eps_color[i] -= (info_segment->eps_color[i] * 2 > info_segment->dx) * info_segment->dx;
		}
	}
}
