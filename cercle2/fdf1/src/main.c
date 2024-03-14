/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:37:45 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/10 17:47:36 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

int close_vars(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img_info->img);
	exit(0);
	return (0);
}

int presse_mouse(int keycode, int x, int y, void *vars)
{
	ft_printf("%d %d %d\n", x, y, keycode, vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars			vars;
	t_all_matrix 	a;
	t_img_info 			img_info;
	t_display_info	*display_info;
	t_all_info all_info;
	t_info_event info_event;
	short point_max;

	if (argc == 2)
	{
		init_info_event(&info_event);
		a.matrix_3_d = read_file_fdf(argv[1], &point_max);
		alloc_matrix_2d(&a);

		display_info = create_display_info(a.display_matrix->width, a.display_matrix->height, point_max);
		transforme_matrix_3d_in2d(&a, display_info);


		vars.mlx = mlx_init();
		vars.img_info = &img_info;
		img_info.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
		img_info.addr = mlx_get_data_addr(img_info.img, &img_info.bits_per_pixel, &img_info.line_length,
										  &img_info.endian);
		img_info.distance_pixel = init_distance_pixel();
		vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Hello world!");
		print_all_ligne(a.display_matrix, &img_info, FALSE);
		all_info.display_info = display_info;
		all_info.all_matrix = &a;
		all_info.vars = &vars;
		all_info.info_event = &info_event;
		mlx_hook(vars.win, 4, (1L<<2)		, button_press, &all_info);
		mlx_hook(vars.win, 5, (1L<<3)		, button_release, &info_event);
		mlx_hook(vars.win, 6, (1L<<6)	, motion_notify, &all_info);
		mlx_hook(vars.win, 17, 1L << 0, close_vars, &vars);
		mlx_hook(vars.win, 2, 1L << 0, keycode_move, &all_info);
		mlx_put_image_to_window(vars.mlx, vars.win, img_info.img, 0, 0);
		mlx_loop(vars.mlx);
	}
	return 0;
}