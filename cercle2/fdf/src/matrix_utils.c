/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:05:29 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/18 22:05:29 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	multiplication_matrix_3x3(float matrix_1[3][3], float matrix_2[3][3], \
float matrix_result[3][3])
{
	int	i;
	int	j;
	int	k;

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

void	multiplication_matrix_3x1(float matrix_1[3][3], \
float matrix_2[3], float matrix_result[3])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		matrix_result[i] = 0;
		while (++j < 3)
			matrix_result[i] += matrix_2[j] * matrix_1[i][j];
	}
}
