/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:35:58 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/07 19:35:58 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

t_display_info 	*create_display_info(int nb_point_width, int nb_point_height)
{
	t_display_info *display_info;
	float			multiplier;

	display_info = malloc(sizeof(t_display_info));
	if (!display_info)
		return (NULL);
	create_identity_matrix(display_info->rotation_vector);
	display_info -> distance_z_min = 1;
	display_info -> move_x = 0;
	display_info -> move_y = 0;
	if (WIDTH / nb_point_width < HEIGHT / nb_point_height)
		multiplier = (WIDTH / nb_point_width) * 0.7;
	else
		multiplier = (HEIGHT / nb_point_height) * 0.7;
	display_info ->multiplier_value_z = multiplier;
	display_info ->distance_point = multiplier;
	return (display_info);
}
