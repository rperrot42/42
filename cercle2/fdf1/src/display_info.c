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

t_display_info 	*create_display_info(int nb_point_width, int nb_point_height, short point_max)
{
	t_display_info *display_info;
	float			multiplier;

	display_info = malloc(sizeof(t_display_info));
	if (!display_info)
		return (NULL);
	display_info -> point_max = point_max;
	create_identity_matrix(display_info->rotation_vector);
	create_vector_multiplicator(display_info->rotation_vector, 20, 15);
	display_info -> width = nb_point_width;
	display_info -> height = nb_point_height;
	display_info -> distance_z_min = point_max * 10;
	display_info -> move_x = 0;
	display_info -> move_y = 0;
	if (WIDTH / nb_point_width < HEIGHT / nb_point_height)
		multiplier = (WIDTH / nb_point_width) * 0.7;
	else
		multiplier = (HEIGHT / nb_point_height) * 0.7;
	display_info ->multiplier_value_z = - 1;
	display_info -> pov = M_PI / 2 - ( M_PI / (display_info -> distance_z_min)) ;
	display_info -> result_pov =  tanf(display_info -> pov);
	display_info ->distance_point = multiplier;
	return (display_info);
}
