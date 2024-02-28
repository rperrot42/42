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

void close_vars(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->data->img);
	exit(0);
}

int print_souris(int keycode, t_vars *vars)
{
	ft_printf("%d souris\n", keycode);
	return (0);
}

int mouvement_souris(int keycode, int x, int y,  t_vars *vars)
{
	ft_printf("%d %d %d mouvemnet souris\n",keycode, x, y);
	//mlx_pixel_put(vars->mlx, vars->win, x, y, create_color(0,255,255,255));
	return (0);
}
int a(int keycode, int x, int y, void *param)
{
	ft_printf("craapace\n");
	return (0);
}
void create_16_line(t_data *img)
{
	t_point	a;
	t_point b;

	a.x = 400;
	a.y = 300;
	b.y = 20;
	b.color=0xFFFF0000;
	a.color=0x0000FFFF;
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

int	main(void)
{
	t_vars	vars;
	t_data 	img;
	vars.mlx = mlx_init();
	vars.data = &img;
	img.img = mlx_new_image(vars.mlx,WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);

	vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");
	create_16_line(&img);
	mlx_hook(vars.win, 17, 1L<<0, close_vars, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}