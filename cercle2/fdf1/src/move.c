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

static void change_multiplier_z(t_display_info *display_info, t_move move);

static void rotation(t_display_info *display_info, t_move move);

int	create_move(void f_move(t_display_info *display_info, t_move move), t_all_info *all_info, t_move move)
{
	print_all_ligne(all_info->all_matrix->display_matrix, all_info->vars->img_info, TRUE);
	f_move(all_info ->display_info, move);
	transforme_matrix_3d_in2d(all_info ->all_matrix, all_info->display_info);
	print_all_ligne(all_info->all_matrix->display_matrix, all_info->vars->img_info, FALSE);
	if (mlx_put_image_to_window(all_info->vars->mlx, all_info->vars->win, all_info->vars->img_info->img, 0, 0) < 0)
		return (-1);
	return (0);

}

static void change_multiplier_z(t_display_info *display_info, t_move move)
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
	printf("%g\n",display_info -> multiplier_value_z);
}

static void rotation(t_display_info *display_info, t_move move)
{
	if (move == LEFT)
		create_vector_multiplicator(display_info->rotation_vector, 1, 0);
	else if (move == RIGHT)
		create_vector_multiplicator(display_info->rotation_vector, -1, 0);
	else if (move == UP)
		create_vector_multiplicator(display_info->rotation_vector, 0, 1);
	else
		create_vector_multiplicator(display_info->rotation_vector, 0, -1);
}

void change_value_min_z(t_display_info *display_info, t_move move)
{
	if (move == UP)
		if (display_info->pov > M_PI / 4)
			display_info->pov -= ((M_PI / 2) - display_info->pov) * 0.1;
		else
			display_info->pov -= display_info->pov * 0.1;
	else {
		if (display_info->pov > M_PI / 4)
			display_info->pov += ((M_PI / 2) - display_info->pov) * 0.1;
		else
			display_info->pov += display_info->pov * 0.1;

	}
	printf("%g\n",display_info->pov);
	display_info -> result_pov = tanf(display_info->pov);
}

int	keycode_move(int keycode, t_all_info *all_info)
{
	print_all_ligne(all_info->all_matrix->display_matrix, all_info->vars->img_info, TRUE);
	if (keycode == KEYCODE_X)
		return (create_move(change_multiplier_z, all_info, UP));
	else if (keycode == KEYCODE_Z)
		return (create_move(change_multiplier_z, all_info, DOWN));
	else if (keycode == KEYCODE_N)
		return (create_move(change_value_min_z, all_info, UP));
	else if (keycode == KEYCODE_M)
		return (create_move(change_value_min_z, all_info, DOWN));
	else if (keycode == KEYCODE_J)
		return (create_move(rotation, all_info, UP));
	else if (keycode == KEYCODE_L)
		return (create_move(rotation, all_info, DOWN));
	else if (keycode == KEYCODE_I)
		return (create_move(rotation, all_info, RIGHT));
	else if (keycode == KEYCODE_K)
		return (create_move(rotation, all_info, LEFT));
	return (0);
}