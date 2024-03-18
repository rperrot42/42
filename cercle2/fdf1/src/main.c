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

#include "./../include/fdf.h"

static t_bool	name_is_valide(char	*name);

static t_all_info	*init_all_info(char *name);

static t_all_matrix 	*init_all_matrix(char *name, short *point_min, short *point_max);

static t_vars	*init_vars();

int	main(int argc, char **argv)
{
	t_all_info *all_info;

	if (argc == 2)
	{
		all_info = init_all_info(argv[1]);
		if (!all_info)
			exit(1);
		transforme_matrix_3d_in2d(all_info->all_matrix, all_info->display_info);
		if (display_all(all_info) < 0)
			return (free_all_info(all_info), 1);
		if (mlx_hook(all_info->vars->win, 4, (1L<<2), button_press, all_info) < 0)
			return (free_all_info(all_info), 1);
		if (mlx_hook(all_info->vars->win, 5, (1L<<3), button_release, all_info->info_event) < 0)
			return (free_all_info(all_info), 1);
		if (mlx_hook(all_info->vars->win, 6, (1L<<6), motion_notify, all_info) < 0)
			return (free_all_info(all_info), 1);
		if (mlx_hook(all_info->vars->win, 17, 1L << 0, free_all_info_sucess, all_info) < 0)
			return (free_all_info(all_info), 1);
		if (mlx_hook(all_info->vars->win, 2, 1L << 0, keycode_move, all_info) < 0)
			return (free_all_info(all_info), 1);
		if (mlx_loop_hook(all_info->vars->mlx, display_all, all_info) < 0)
			return (free_all_info(all_info), 1);
		if (mlx_loop(all_info->vars->mlx))
			return (free_all_info(all_info), 1);

	}
	return 0;
}
static t_all_info	*init_all_info(char *name)
{
	t_all_info	*all_info;
	short 		point_min;
	short 		point_max;

	if (name_is_valide(name) == FALSE)
		exit(EXIT_FAILURE);
	all_info = malloc(sizeof(t_all_info));
	if (!all_info)
		return (NULL);
	all_info->info_event = NULL;
	all_info->vars = NULL;
	all_info->display_info = NULL;
	all_info -> all_matrix = init_all_matrix(name, &point_min, &point_max);
	if (!all_info -> all_matrix)
		return (free_all_info(all_info), NULL);
	all_info -> display_info = create_display_info(all_info->all_matrix->matrix_3_d->width,all_info->all_matrix->matrix_3_d->height, point_max, point_min);
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

static t_all_matrix 	*init_all_matrix(char *name, short *point_min, short *point_max)
{
	t_all_matrix *all_matrix;

	all_matrix = malloc(sizeof(t_all_matrix));
	if (!all_matrix)
		return (NULL);
	all_matrix->matrix_3_d = read_file_fdf(name, point_max, point_min);
	if (!all_matrix->matrix_3_d)
		return (free(all_matrix), NULL);
	alloc_matrix_2d(all_matrix);
	if (!all_matrix -> display_matrix)
		return (free_matrix_3d(all_matrix->matrix_3_d, all_matrix->matrix_3_d->height), free(all_matrix), NULL);
	return (all_matrix);
}

static t_vars	*init_vars()
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
	vars->img_info->addr = mlx_get_data_addr(vars->img_info->img, &vars->img_info->bits_per_pixel, &vars->img_info->line_length,
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

static t_bool	name_is_valide(char	*name)
{
	int	len_str;
	int len_file_ext_fdf;

	len_str = ft_strlen(name);
	len_file_ext_fdf = ft_strlen(FILE_EXTENSION_FDF);
	if (len_str < len_file_ext_fdf)
		return (FALSE);
	if (ft_strncmp(name + len_str - len_file_ext_fdf, FILE_EXTENSION_FDF, len_file_ext_fdf))
		return (FALSE);
	return (TRUE);
}