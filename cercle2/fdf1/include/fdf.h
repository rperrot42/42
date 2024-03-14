/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:46:16 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/11 13:05:54 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include <float.h>

# ifdef __APPLE__
#  define KEYCODE_I 34
#  define KEYCODE_K 40
#  define KEYCODE_L 37
#  define KEYCODE_J 38
#  define KEYCODE_X 7
#  define KEYCODE_Z 6
#  define KEYCODE_M 46
#  define KEYCODE_N 45
#  define RIGHT_CLICK 2
# else
#  define KEYCODE_X 120
#  define KEYCODE_Z 122
#  define KEYCODE_M 109
#  define KEYCODE_N 110
#  define KEYCODE_I 105
#  define KEYCODE_K 107
#  define KEYCODE_L 108
#  define KEYCODE_J 106
#  define RIGHT_CLICK 3
# endif
# define LEFT_CLICK 1
# define HEIGHT 600
# define WIDTH 800
# define SCROLING_UP 5
# define SCROLING_DOWN 4
# define ROTATION_MOVE 0.005
# define BASE_10 "0123456789"
# define BASE_HEXA "0123456789abcdef"
# define SPEED_ZOOM 0.03
# define ROTATION_X_START 0
# define ROTATION_Y_START 0

typedef enum	e_move
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_move;

typedef struct	s_pixel
{
	short			x;
	short			y;
	unsigned int	color;
}	t_pixel;

typedef struct	s_point_3d
{
	float				z;
	int 			x;
	int 			y;
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

typedef struct	s_rotation
{
	float	rotation_x;
	float	rotation_y;
	float	rotation_z;
}	t_rotation;


typedef struct s_display_info
{
	float		distance_z_min;
	float		multiplier_value_z;
	float		distance_point;
	short 		move_y;
	short		move_x;
	float		rotation_vector[3][3];
	int			width;
	int			height;
	short		point_max;
	float 		pov;
	float 		result_pov;
	unsigned int	color_negative;
	unsigned int 	color_null;
	unsigned int color_mid;
	unsigned int color_max;
}	t_display_info;

typedef struct s_info_segment
{
	int				dx;
	int				dy;
	int				eps;
	int				eps_color[4];
	unsigned char	d_color[4];
	char			avanc_color[4];
	t_bool			dy_is_sup_dx;
	char			avanc;
	t_bool			black_color;
	float 			avanc_z;
}	t_info_segment;

typedef struct	s_img_info {
	void	*img;
	char	*addr;
	float	**distance_pixel;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_info;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_img_info	*img_info;
}	t_vars;

typedef struct	s_all_matrix
{
	t_matrix_3d 		*matrix_3_d;
	t_display_matrix	*display_matrix;
}	t_all_matrix;

typedef struct s_info_event
{
	t_bool	left_click;
	t_bool	right_click;
	short	position_x;
	short	position_y;
}	t_info_event;

typedef struct s_all_info
{
	t_all_matrix	*all_matrix;
	t_display_info	*display_info;
	t_vars			*vars;
	t_info_event	*info_event;
}	t_all_info;


void my_mlx_pixel_put(t_img_info *img, int x, int y, unsigned int color);

void	create_line_all(t_img_info *img, t_point_3d a, t_point_3d b, t_bool	black_color);
int		create_color(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
void 	init_color_line(t_point_3d *a, t_point_3d *b, t_info_segment *info_segment);
void	create_color_line(t_point_3d *a, t_info_segment *info_segment);
int 	close_vars(t_vars *vars);
t_matrix_3d 	*read_file_fdf(char *name_file , short *point_3d_max);
t_point_z	create_point3d(char **line);
void	free_matrix_3d(t_matrix_3d *matrix_3d);
t_bool	alloc_matrix_2d(t_all_matrix *all_matrix);
void	free_display_matrix(t_display_matrix *display_matrix);
void	transforme_matrix_3d_in2d(t_all_matrix *all_matrix, t_display_info *display_info);
void	print_all_ligne(t_display_matrix *display_matrix, t_img_info *img, t_bool black_color);
void	multiplication_matrix_3x3(float matrix_1[3][3], float matrix_2[3][3], float matrix_result[3][3]);
void	create_identity_matrix(float matrix_result[3][3]);
void	multiplication_matrix_3x1(float matrix_1[3][3], float matrix_2[3], float matrix_result[3]);
t_display_info 	*create_display_info(int nb_point_width, int nb_point_height, short point_max);
int	keycode_move(int keycode, t_all_info *all_info);
void	init_info_event(t_info_event *info_event);
int	button_press(int keycode, int x, int y, t_all_info *all_info);
int	button_release(int keycode, int x, int y, t_info_event *info_event);
int	create_move(void f_move(t_display_info *display_info, t_move move), t_all_info *all_info, t_move move);
int	motion_notify(int x, int y, t_all_info *all_info);
void change_display_matrix(t_display_matrix *display_matrix, short x, short y);
void	create_vector_multiplicator(float vector_multiplicator[3][3], int rotation_x, int rotation_y);
void change_value_min_z(t_display_info *display_info, t_move move);
void	free_distance_pixel(float **distance_pixel, int size);
void	put_distance_pixel_float_max(float **distance_pixel);
float	**init_distance_pixel(void);
#endif
