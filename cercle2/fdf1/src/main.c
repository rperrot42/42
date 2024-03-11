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
/*
void create_16_line(t_data *img)
{
	t_pixel	a;
	t_pixel b;

	a.x = 400;
	a.y = 300;
	b.y = 20;
	b.color=0x00000000;
	a.color=0x00FFFFFF;
	int	i = -1;
	while (++i < 4)
	{

		b.x = 20 + (190 * i);
		create_line_all(img,a, b);
	}
	i = -1;
	b.x = 780;
	while (++i < 4)
	{
		b.y = 20 + (140 * i);
		create_line_all(img,a, b);
	}
	i = -1;
	b.y = 580;
	while (++i < 4)
	{
		b.x = 780 - (190 * i);
		create_line_all(img,a, b);
	}
	i = -1;
	b.x = 20;
	while (++i < 4)
	{
		b.y = 580 - (140 * i);
		create_line_all(img,a, b);
	}

}
*/
int presse_mouse(int keycode, int x, int y, void *vars)
{
	ft_printf("%d %d %d\n", x, y, keycode, vars);
	return (0);
}
int	main(int argc, char **argv)
{
	/*
	float m3[3][3] = {{89, 4545, 12},
					  {51, 23 , 9},
					  {89, 45, 3}};
	float m1[3] = {5,4,8};
	float m2[3];
	multiplication_matrix_3x1(m3, m1, m2);
	//t_rotation rot;

	rot.rotation_x = 1.0471975512;
	rot.rotation_y =  1.0471975512;
	rot.rotation_z =  1.0471975512;
	create_rotation_matrix(&rot, m3);
	int i= -1;
	while (++i < 3) {
		printf("%g %g %g\n", m3[i][0], m3[i][1], m3[i][2]);
	}
	printf("%g %g %g\n", m2[0], m2[1], m2[2]);
	*/

	t_vars			vars;
	t_all_matrix 	a;
	t_img_info 			img_info;
	t_display_info	*display_info;
	t_all_info all_info;
	t_info_event info_event;

	if (argc == 2)
	{
		init_info_event(&info_event);
		a.matrix_3_d = read_file_fdf(argv[1]);
		alloc_matrix_2d(&a);

		display_info = create_display_info(a.display_matrix->width, a.display_matrix->height);
		transforme_matrix_3d_in2d(&a, display_info);


		vars.mlx = mlx_init();
		vars.img_info = &img_info;
		img_info.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
		img_info.addr = mlx_get_data_addr(img_info.img, &img_info.bits_per_pixel, &img_info.line_length,
										  &img_info.endian);
		vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");
		print_all_ligne(a.display_matrix, &img_info, FALSE);
		all_info.display_info = display_info;
		all_info.all_matrix = &a;
		all_info.vars = &vars;
		all_info.info_event = &info_event;
		mlx_hook(vars.win, 4, (1L<<2)		, button_press, &info_event);
		mlx_hook(vars.win, 5, (0)	, button_release, &info_event);
		mlx_hook(vars.win, 6, (0)	, motion_notify, &all_info);
		mlx_hook(vars.win, 17, 1L << 0, close_vars, &vars);
		mlx_hook(vars.win, 2, 1L << 0, keycode_move, &all_info);
		mlx_put_image_to_window(vars.mlx, vars.win, img_info.img, 0, 0);
		mlx_loop(vars.mlx);
	}
	return 0;
}