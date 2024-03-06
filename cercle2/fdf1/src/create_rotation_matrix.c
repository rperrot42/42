/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rotation_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:17:09 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/06 13:17:09 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

static void	create_matrix_rotation_x(float matrix_result[3][3], float rotation_x);

static void	create_matrix_rotation_y(float matrix_result[3][3], float rotation_y);

//static void	create_matrix_rotation_z(float matrix_result[3][3], float rotation_z);

void	multiplication_matrix_3x1(float matrix_1[3][3], float matrix_2[3], float matrix_result[3])
{
	int	i;
	int j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		matrix_result[i] = 0;
		while(++j < 3)
			matrix_result[i] += matrix_2[j] * matrix_1[i][j];
	}
}

void	multiplication_matrix_3x3(float matrix_1[3][3], float matrix_2[3][3], float matrix_result[3][3])
{
	int	i;
	int	j;
	int k;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			k = -1;
			matrix_result[i][j] = 0;
			while (++k < 3)
				matrix_result[i][j] += matrix_1[i][k] * matrix_2[k][j];
		}
	}
}

void	create_rotation_matrix(t_rotation *rotation, float matrix_result[3][3])
{
	float matrix_rot_1[3][3];
	float matrix_rot_2[3][3];

	create_matrix_rotation_x(matrix_rot_1, rotation->rotation_x);
	create_matrix_rotation_y(matrix_rot_2, rotation->rotation_y);
	multiplication_matrix_3x3(matrix_rot_1, matrix_rot_2, matrix_result);
}

static void	create_matrix_rotation_x(float matrix_result[3][3], float rotation_x)
{
	float	cos_x;
	float	sin_x;
	int 	i;

	matrix_result[0][0] = 1;
	i = 0;
	while (++i < 3)
	{
		matrix_result[i][0] = 0;
		matrix_result[0][i] = 0;
	}
	cos_x = cosf(rotation_x);
	sin_x = sinf(rotation_x);
	matrix_result[1][1] = cos_x;
	matrix_result[1][2] = -sin_x;
	matrix_result[2][1] = sin_x;
	matrix_result[2][2] = cos_x;
}

static void	create_matrix_rotation_y(float matrix_result[3][3], float rotation_y)
{
	float	cos_y;
	float	sin_y;

	cos_y = cosf(rotation_y);
	sin_y = sinf(rotation_y);
	matrix_result[1][1] = 1;
	matrix_result[0][1] = 0;
	matrix_result[1][0] = 0;
	matrix_result[1][2] = 0;
	matrix_result[2][1] = 0;
	matrix_result[0][0] = cos_y;
	matrix_result[0][2] = sin_y;
	matrix_result[2][0] = -sin_y;
	matrix_result[2][2] = cos_y;
}
/*
static void	create_matrix_rotation_z(float matrix_result[3][3], float rotation_z)
{
	float	cos_z;
	float	sin_z;
	int 	i;

	matrix_result[2][2] = 1;
	i = -1;
	while (++i < 2)
	{
		matrix_result[i][2] = 0;
		matrix_result[2][i] = 0;
	}
	cos_z = cosf(rotation_z);
	sin_z = sinf(rotation_z);
	matrix_result[0][0] = cos_z;
	matrix_result[1][0] = sin_z;
	matrix_result[0][1] = -sin_z;
	matrix_result[1][1] = cos_z;
}*/