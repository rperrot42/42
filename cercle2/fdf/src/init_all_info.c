/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:37:45 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/17 21:28:44 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_all_matrix	*init_all_matrix(char *name, short *point_min, \
short *point_max);

static t_vars		*init_vars(void);

static t_vars		*init_window_and_addr(t_vars *vars);

t_all_info	*init_all_info(char *name)
{
	t_all_info	*all_info;
	short		point_min;
	short		point_max;

	all_info = malloc(sizeof(t_all_info));
	if (!all_info)
		return (NULL);
	all_info->info_event = NULL;
	all_info->vars = NULL;
	all_info->display_info = NULL;
	all_info -> all_matrix = init_all_matrix(name, &point_min, &point_max);
	if (!all_info -> all_matrix)
		return (free_all_info(all_info), NULL);
	all_info -> display_info = \
	create_display_info(all_info->all_matrix->matrix_3_d->width, \
	all_info->all_matrix->matrix_3_d->height, point_max, point_min);
	if (!all_info -> display_info)
		return (free_all_info(all_info), NULL);
	all_info -> info_event = init_info_event();
	if (!all_info -> info_event)
		return (free_all_info(all_info), NULL);
	all_info ->vars = init_vars();
	if (!all_info -> vars)
		return (free_all_info(all_info), NULL);
	return (all_info);
}

static t_all_matrix	*init_all_matrix(char *name, \
short *point_min, short *point_max)
{
	t_all_matrix	*all_matrix;

	all_matrix = malloc(sizeof(t_all_matrix));
	if (!all_matrix)
		return (NULL);
	all_matrix->matrix_3_d = read_file_fdf(name, point_max, point_min);
	if (!all_matrix->matrix_3_d)
		return (free(all_matrix), NULL);
	alloc_matrix_2d(all_matrix);
	if (!all_matrix -> display_matrix)
		return (free_matrix_3d(all_matrix->matrix_3_d, \
		all_matrix->matrix_3_d->height), free(all_matrix), NULL);
	return (all_matrix);
}

static t_vars	*init_vars(void)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->img_info = malloc(sizeof (t_img_info));
	if (!vars->img_info)
		return (free(vars), NULL);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (free(vars->img_info), free(vars), NULL);
	vars->win = NULL;
	vars->img_info->addr = NULL;
	vars->img_info->distance_pixel = NULL;
	vars->img_info->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars -> img_info -> img)
		return (free_vars(vars), NULL);
	return (init_window_and_addr(vars));
}

static t_vars	*init_window_and_addr(t_vars	*vars)
{
	vars->img_info->addr = mlx_get_data_addr(vars->img_info->img, \
&vars->img_info->bits_per_pixel, &vars->img_info->line_length, \
	&vars->img_info->endian);
	if (!vars->img_info->addr)
		return (free_vars(vars), NULL);
	vars->img_info->distance_pixel = init_distance_pixel();
	if (!vars->img_info->distance_pixel)
		return (free_vars(vars), NULL);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Hello world!");
	if (!vars->win)
		return (free_vars(vars), NULL);
	return (vars);
}
