/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:07:59 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/03 13:07:59 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_all_info_sucess(t_all_info *all_info)
{
	free_all_info(all_info);
	exit(0);
	return (0);
}

void	free_all_info(t_all_info *all_info)
{
	if (all_info->all_matrix && all_info->all_matrix->matrix_3_d)
		free_matrix_3d(all_info->all_matrix->matrix_3_d, \
		all_info->all_matrix->matrix_3_d->height);
	if (all_info->all_matrix && all_info->all_matrix->display_matrix)
		free_display_matrix(all_info->all_matrix->display_matrix);
	free(all_info->display_info);
	free(all_info->all_matrix);
	free(all_info->info_event);
	free_vars(all_info->vars);
	free(all_info);
}

void	free_vars(t_vars *vars)
{
	if (vars)
	{
		if (vars ->img_info && vars->img_info->img)
			mlx_destroy_image(vars->mlx, vars->img_info->img);
		if (vars ->img_info && vars->img_info->distance_pixel)
			free_distance_pixel(vars->img_info->distance_pixel, HEIGHT);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		if (vars->mlx)
		{
			mlx_destroy_display(vars->mlx);
			free(vars->mlx);
		}
		if (vars->img_info)
			free(vars->img_info);
		free(vars);
	}
}

void	free_matrix_3d(t_matrix_3d *matrix_3d, int height)
{
	int	i;

	i = -1;
	if (!height)
		height = matrix_3d -> height;
	while (++i < height)
		free(matrix_3d ->matrix_point[i]);
	free(matrix_3d -> matrix_point);
	free(matrix_3d);
}

void	free_display_matrix(t_display_matrix *display_matrix)
{
	int	i;

	i = -1;
	while (++i < display_matrix -> height)
	{
		if (!display_matrix->display_pixel[i])
			break ;
		free(display_matrix->display_pixel[i]);
	}
	free(display_matrix ->display_pixel);
	free(display_matrix);
}
