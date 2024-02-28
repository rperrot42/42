/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:46:16 by rperrot           #+#    #+#             */
/*   Updated: 2024/02/10 17:46:25 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
#define FDF_FDF_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include "./../libft/libft.h"

#define HEIGHT 600
#define WIDTH 800



typedef struct	s_point
{
	short	x;
	short	y;
	short	z;
	int		color;
}	t_point;

typedef struct s_info_segment
{
	short			dx;
	short			dy;
	short			eps;
	short	eps_color[4];
	unsigned char	d_color[4];
	char			avanc_color[4];
	t_bool			dy_is_sup_dx;
	char			avanc;
}	t_info_segment;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	*data;
}				t_vars;
void my_mlx_pixel_put(t_data *img, int x, int y, unsigned int color);

void	create_line_all(t_data *img, t_point a, t_point b);
int create_color(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
void 	init_color_line(t_point *a, t_point *b, t_info_segment *info_segment);
void	create_color_line(t_point *a, t_info_segment *info_segment);
void	close_vars(t_vars *vars);
#endif //FDF_FDF_H
