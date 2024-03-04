/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:07:59 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/03 13:07:59 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

void	free_matrix_3d(t_matrix_3d *matrix_3d)
{
	int	i;

	i = -1;
	while (++i < matrix_3d -> height)
		free(matrix_3d ->matrix_point[i]);
	free(matrix_3d);
}
