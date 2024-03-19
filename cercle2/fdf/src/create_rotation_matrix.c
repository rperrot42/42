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

#include "fdf.h"

static void	create_matrix_rotation_x(float matrix_result[3][3], int rotation_x);

static void	create_matrix_rotation_y(float matrix_result[3][3], int rotation_y);

static void	cp_matrix_3x3(float matrix1[3][3], float matrix2[3][3]);

static void	cp_matrix_3x3(float matrix[3][3], float cp_matrix[3][3])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			cp_matrix[i][j] = matrix[i][j];
	}
}

void	create_vector_multiplicator(float vector_multiplicator[3][3], \
int rotation_x, int rotation_y)
{
	float	matrix_multiplicator[3][3];
	float	result_matrix[3][3];

	if (rotation_x != 0)
	{
		create_matrix_rotation_x(matrix_multiplicator, rotation_x);
		multiplication_matrix_3x3(matrix_multiplicator, vector_multiplicator, \
		result_matrix);
		cp_matrix_3x3(result_matrix, vector_multiplicator);
	}
	if (rotation_y != 0)
	{
		create_matrix_rotation_y(matrix_multiplicator, rotation_y);
		multiplication_matrix_3x3(matrix_multiplicator, vector_multiplicator, \
		result_matrix);
		cp_matrix_3x3(result_matrix, vector_multiplicator);
	}
}

void	create_identity_matrix(float matrix_result[3][3])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			if (i == j)
				matrix_result[i][j] = 1;
			else
				matrix_result[i][j] = 0;
		}
	}
}

static void	create_matrix_rotation_x(float matrix_result[3][3], int rotation_x)
{
	float	cos_x;
	float	sin_x;
	int		i;

	matrix_result[0][0] = 1;
	i = 0;
	while (++i < 3)
	{
		matrix_result[i][0] = 0;
		matrix_result[0][i] = 0;
	}
	cos_x = cosf(ROTATION_MOVE * rotation_x);
	sin_x = sinf(ROTATION_MOVE * rotation_x);
	matrix_result[1][1] = cos_x;
	matrix_result[1][2] = -sin_x;
	matrix_result[2][1] = sin_x;
	matrix_result[2][2] = cos_x;
}

static void	create_matrix_rotation_y(float matrix_result[3][3], int rotation_y)
{
	float	cos_y;
	float	sin_y;

	cos_y = cosf(ROTATION_MOVE * rotation_y);
	sin_y = sinf(ROTATION_MOVE * rotation_y);
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
