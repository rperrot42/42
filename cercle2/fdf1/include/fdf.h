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
#include <math.h>
#include "./../libft/libft.h"

#define HEIGHT 600
#define WIDTH 800

#define BASE_10 "0123456789"
#define BASE_HEXA "0123456789ABCDEF"


typedef struct	s_pixel
{
	short			x;
	short			y;
	unsigned int	color;
}	t_pixel;

typedef struct	s_point_3d
{
	short			z;
	short 			x;
	short 			y;
	unsigned int	color;
}	t_point_3d;

typedef struct	s_display_matrix
{
	int			width;
	int			height;
	t_point_3d		**display_pixel;
}	t_display_matrix;

typedef	struct	s_point_z
{
	short			z;
	unsigned int	color;
}	t_point_z;


typedef struct	s_matrix_3d
{
	int			width;
	int			height;
	t_point_z	**matrix_point;
}	t_matrix_3d;

typedef struct s_info_segment
{
	short			dx;
	short			dy;
	short			eps;
	short			eps_color[4];
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
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	*data;
}	t_vars;

typedef struct	s_all_matrix
{
	t_matrix_3d 		*matrix_3_d;
	t_display_matrix	*display_matrix;
}	t_all_matrix;

typedef struct	s_rotation
{
	float	rotation_x;
	float	rotation_y;
	float	rotation_z;
}	t_rotation;


void my_mlx_pixel_put(t_data *img, int x, int y, unsigned int color);

void	create_line_all(t_data *img, t_point_3d a, t_point_3d b);
int		create_color(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
void 	init_color_line(t_point_3d *a, t_point_3d *b, t_info_segment *info_segment);
void	create_color_line(t_point_3d *a, t_info_segment *info_segment);
int 	close_vars(t_vars *vars);
t_matrix_3d 	*read_file_fdf(char *name_file);
t_point_z	create_point3d(char **line);
void	free_matrix_3d(t_matrix_3d *matrix_3d);
t_bool	alloc_matrix_2d(t_all_matrix *all_matrix);
void	free_display_matrix(t_display_matrix *display_matrix);
void	transforme_matrix_3d_in2d(t_all_matrix *all_matrix);
void	print_all_ligne(t_display_matrix *display_matrix, t_data *img);
void	multiplication_matrix_3x3(float matrix_1[3][3], float matrix_2[3][3], float matrix_result[3][3]);
void	create_rotation_matrix(t_rotation *rotation, float matrix_result[3][3]);
void	multiplication_matrix_3x1(float matrix_1[3][3], float matrix_2[3], float matrix_result[3]);

#endif //FDF_FDF_H
