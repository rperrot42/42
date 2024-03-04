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
	mlx_destroy_image(vars->mlx, vars->data->img);
	exit(0);
	return (0);
}
void create_16_line(t_data *img)
{
	t_point	a;
	t_point b;

	a.x = 400;
	a.y = 300;
	b.y = 20;
	b.color=0x09a5e5f3;
	a.color=0x578a5d5f;
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

int	main(int argc, char **argv)
{
	t_matrix_3d 	*a;
	int i;
	int j;

	if (argc == 2) {
		a = malloc(100);
		a = read_file_fdf(argv[1]);
		i = -1;
		while (++i < a-> height)
		{
			j = -1;
			while (++j < a->width)
			{
				ft_printf("%d %u\n", a->matrix_point[i][j].color,  a->matrix_point[i][j].z);
			}
		}
	}
	/*
	vars.mlx = mlx_init();
	vars.data = &img;
	img.img = mlx_new_image(vars.mlx,WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");
	create_16_line(&img);
	mlx_hook(vars.win, 17, 1L<<0, close_vars, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);*/
}