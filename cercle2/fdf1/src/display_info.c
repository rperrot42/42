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

t_display_info 	*create_display_info(int nb_point_width, int nb_point_height, short point_max, short point_min)
{
	t_display_info *display_info;
	float			multiplier;
	short 			size_max;

	display_info = malloc(sizeof(t_display_info));
	if (!display_info)
		return (NULL);
	size_max = nb_point_width;
	if (nb_point_height > size_max)
		size_max = nb_point_height;
	if (point_max > size_max)
		size_max = point_max;
	if (point_min * -1 > size_max)
		size_max = point_min * -1;
	display_info -> point_max = point_max;
	create_vector_multiplicator(display_info->rotation_vector, 20, 15);
	display_info -> width = nb_point_width;
	display_info -> height = nb_point_height;
	display_info -> distance_z_min = size_max * 10;
	if (WIDTH / nb_point_width < HEIGHT / nb_point_height)
		multiplier = (WIDTH * 0.7 / nb_point_width);
	else
		multiplier = (HEIGHT * 0.7 / nb_point_height);
	display_info ->distance_point = multiplier;
	display_info -> color_negative[0] =  0x243566;
	display_info -> color_mid[0] =   0x9d7153;
	display_info -> color_null[0] = 0x527048;
	display_info -> color_max[0] = 0xFFFFFF;
	display_info -> color_negative[1] =  0xFFFFFF;
	display_info -> color_mid[1] =   0x888888;
	display_info -> color_null[1] = 0x000000;
	display_info -> color_max[1] = 0xFFFFFF;
	display_info -> point_min = point_min;
	renitialise_display_info(display_info);
	return (display_info);
}

void	renitialise_display_info(t_display_info *display_info)
{
	create_identity_matrix(display_info->rotation_vector);
	create_vector_multiplicator(display_info ->rotation_vector, ROTATION_X_START, ROTATION_Y_START);
	display_info -> pov = M_PI / 2 - ( M_PI / (display_info -> distance_z_min) * 0.4) ;
	display_info -> result_pov =  tanf(display_info -> pov);
	display_info ->multiplier_value_z = - 1;
	display_info -> move_x = 0;
	display_info -> move_y = 0;
	display_info -> actual_color = 0;
	display_info -> print_point = FALSE;
}