/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:18:59 by rperrot           #+#    #+#             */
/*   Updated: 2024/03/08 16:19:06 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/fdf.h"

static int change_multiplier_z(t_display_info *display_info, t_move move);

static int rotation(t_display_info *display_info, t_move move);

int	display_all(t_all_info *all_info)
{
	print_all_ligne(all_info->all_matrix->display_matrix, all_info->vars->img_info, TRUE, FALSE);
	transforme_matrix_3d_in2d(all_info ->all_matrix, all_info->display_info);
	print_all_ligne(all_info->all_matrix->display_matrix, all_info->vars->img_info, FALSE,  all_info->display_info->print_point);
	if (mlx_put_image_to_window(all_info->vars->mlx, all_info->vars->win, all_info->vars->img_info->img, 0, 0) < 0)
		return (-1);
	return (0);

}

static int change_multiplier_z(t_display_info *display_info, t_move move)
{
	if (display_info -> multiplier_value_z > 0)
		if (move == DOWN)
			display_info -> multiplier_value_z = display_info -> multiplier_value_z * 0.95 - 0.01;
		else
			display_info -> multiplier_value_z = display_info -> multiplier_value_z * 1.05 + 0.01;
	else
		if (move == DOWN)
			display_info -> multiplier_value_z = display_info -> multiplier_value_z * 1.05 - 0.01;
		else
			display_info -> multiplier_value_z = display_info -> multiplier_value_z * 0.95 + 0.01;
	return (0);
}

static int rotation(t_display_info *display_info, t_move move)
{
	if (move == LEFT)
		create_vector_multiplicator(display_info->rotation_vector, 1, 0);
	else if (move == RIGHT)
		create_vector_multiplicator(display_info->rotation_vector, -1, 0);
	else if (move == UP)
		create_vector_multiplicator(display_info->rotation_vector, 0, 1);
	else
		create_vector_multiplicator(display_info->rotation_vector, 0, -1);
	return (0);
}

int change_value_min_z(t_display_info *display_info, t_move move)
{
	if (move == UP)
	{
		if (display_info->pov > M_PI / 4)
			display_info->pov -= ((M_PI / 2) - display_info->pov) * SPEED_ZOOM - 0.0000003;
		else
			display_info->pov -= display_info->pov * SPEED_ZOOM;
	}
	else
	{
		if (display_info->pov > M_PI / 4)
			display_info->pov += ((M_PI / 2) - display_info->pov) * SPEED_ZOOM;
		else
			display_info->pov += display_info->pov * SPEED_ZOOM;
	}
	display_info -> result_pov = tanf(display_info->pov);
	return (0);
}

int	keycode_move(int keycode, t_display_info *display_info)
{
	if (keycode == KEYCODE_X)
		return (change_multiplier_z(display_info, UP));
	else if (keycode == KEYCODE_Z)
		return (change_multiplier_z(display_info, DOWN));
	else if (keycode == KEYCODE_N)
		return (change_multiplier_z(display_info, UP));
	else if (keycode == KEYCODE_M)
		return (change_value_min_z (display_info, DOWN));
	else if (keycode == KEYCODE_J)
		return (rotation(display_info, UP));
	else if (keycode == KEYCODE_L)
		return (rotation(display_info, DOWN));
	else if (keycode == KEYCODE_I)
		return (rotation(display_info, RIGHT));
	else if (keycode == KEYCODE_K)
		return (rotation(display_info, LEFT));
	else if (keycode == KEYCODE_SP)
		return (renitialise_display_info(display_info), 0);
	else if (keycode == KEYCODE_P)
		display_info->print_point = (display_info->print_point + 1) % 2;
	else if (keycode == KEYCODE_C)
		display_info->actual_color = (display_info->actual_color + 1) % COLOR_MAX;
	return (0);
}